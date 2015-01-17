#include "Rio.h"
#include "SocketBase.h"

#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

#include <vector>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 4096
#define MAXBUFF 1024*1024

using namespace blink;

void doit(int fd);
void readRequestHeaderResponse(Rio& rio);
int parseUri(char* uri, char* filename, char* cgiargs);
void serveStatic(int fd, Rio& rio, char* filename, int filesize);
void getFileType(char* filename, char* filetype);
void serveDynamic(int fd, Rio& rio, char* filename, char* cgiargs);
void clientError(int fd, Rio& rio, const char* cause, const char* error_num,
	             const char* short_message, const char* long_message);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	int port = atoi(argv[1]);
	int listenfd = sockets::openListenFd(port);
	int connectfd = -1;
	struct sockaddr_in clientaddr;
	int clientlen = sizeof(clientaddr);
	char addrp[20];
	while (true)
	{
		connectfd = sockets::accept(listenfd, sockets::sockaddr_cast(&clientaddr), &clientlen);
		if (connectfd >= 0)
		{
			sockets::inet_ntop(AF_INET, &clientaddr.sin_addr, addrp, sizeof(addrp));
			printf("server connected to %s\n", addrp);
			doit(connectfd);
			if (sockets::close(connectfd) >= 0)
			{
				fprintf(stderr, "closed connect: from %s\n", addrp);
			}
		}
	}
	return 0;
}

void doit(int fd)
{
	Rio rio(fd);
	std::vector<char> buf(MAXLINE);
	std::vector<char> method(MAXLINE);
	std::vector<char> uri(MAXLINE);
	std::vector<char> version(MAXLINE);
	rio.readlineb(&buf[0], MAXLINE);
	sscanf(&buf[0], "%s %s %s", &method[0], &uri[0], &version[0]);
	if (strcasecmp(&method[0], "GET") != 0)
	{
		clientError(fd, rio, &method[0], "501", "Not Implemented", "Don't implement this mothod");
		return;
	}
	readRequestHeaderResponse(rio);
	std::vector<char> filename(MAXLINE);
	std::vector<char> cgiargs(MAXLINE);
	int is_static = parseUri(&uri[0], &filename[0], &cgiargs[0]);
	struct stat sbuf;
	if (stat(&filename[0], &sbuf) < 0)
	{
		clientError(fd, rio, &filename[0], "404", "Not found", "Couldn't find this file");
		return;
	}
	if (is_static)
	{
		if (!S_ISREG(sbuf.st_mode) || !(S_IXUSR & sbuf.st_mode))
		{
			clientError(fd, rio, &filename[0], "403", "Forbidden", "Couldn't read thie file");
			return;
		}
		serveStatic(fd, rio, &filename[0], sbuf.st_size);
	}
	else
	{
		if (!S_ISREG(sbuf.st_mode) || !(S_IXUSR & sbuf.st_mode))
		{
			clientError(fd, rio, &filename[0], "403", "Forbidden", "Couldn't run the CGI program");
			return;
		}
		serveDynamic(fd, rio, &filename[0], &cgiargs[0]);
	}
}

void readRequestHeaderResponse(Rio& rio)
{
	std::vector<char> buf(MAXLINE);
	rio.readlineb(&buf[0], MAXLINE);
	while(strcmp(&buf[0], "\r\n") != 0)
	{
		if (rio.readlineb(&buf[0], MAXLINE) == 0)
		{
			break;
		}
		fprintf(stderr, "%s\n", &buf[0]);
	}
}

int parseUri(char* uri, char* filename, char* cgiargs)
{
	if (!strstr(uri, "cgi-bin"))
	{
		strcpy(cgiargs, "");
		strcpy(filename, ".");
		strcat(filename, uri);
		if (uri[strlen(uri) - 1] == '/')
		{
			strcat(filename, "home.html");
		}
		return 1;
	}
	else
	{
		char* ptr = index(uri, '?');
		if (ptr)
		{
			strcpy(cgiargs, ptr + 1);
			*ptr = '\0';
		}
		else
		{
			strcpy(cgiargs, "");
		}
		strcpy(filename, ".");
		strcat(filename, uri);
		return 0;
	}
}

void serveStatic(int fd, Rio& rio, char* filename, int filesize)
{
	std::vector<char> buf(MAXBUFF);
	std::vector<char> filetype(MAXLINE);
	getFileType(filename, &filetype[0]);
	sprintf(&buf[0], "HTTP/1.0 200 OK\r\n");
	sprintf(&buf[0], "%sServer: Web Server\r\n", &buf[0]);
	sprintf(&buf[0], "%sContent-length: %d", &buf[0], filesize);
	sprintf(&buf[0], "%sContent-type: %s\r\n\r\n", &buf[0], &filetype[0]);
	rio.writen(&buf[0], strlen(&buf[0]));

	int filefd = ::open(filename, O_RDONLY, 0);
	if (filefd < 0)
	{
		fprintf(stderr, "open error: open %s failed.\n", filename);
		return;
	}
	void* srcp = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, filefd, 0);
	if (srcp == MAP_FAILED)
	{
		fprintf(stderr, "mmap error: mmap %s failed.\n", filename);
		return;
	}
	rio.writen(srcp, filesize);
	if (::close(filefd) < 0)
	{
		fprintf(stderr, "close error: close %s failed\n", filename);
		return;
	}
	if (munmap(srcp, filesize) < 0)
	{
		fprintf(stderr, "munmap error\n");
		return;
	}
}

void getFileType(char* filename, char* filetype)
{
	if (strstr(filename, ".html"))
	{
		strcpy(filetype, "text/html");
	}
	else if (strstr(filename, ".gif"))
	{
		strcpy(filetype, "image/gif");
	}
	else if (strstr(filename, ".jpg"))
	{
		strcpy(filetype, "image/jpg");
	}
	else
	{
		strcpy(filetype, "text/plain");
	}
}

void serveDynamic(int fd, Rio& rio, char* filename, char* cgiargs)
{
	std::vector<char> buf(MAXLINE);
	sprintf(&buf[0], "HTTP/1.0 200 OK\r\n");
	rio.writen(&buf[0], strlen(&buf[0]));
	sprintf(&buf[0], "Server: Web Server\r\n");
	rio.writen(&buf[0], strlen(&buf[0]));
	int val_fork = fork();
	if (val_fork < 0)
	{
		fprintf(stderr, "fork error\n");
		return;
	}
	if (val_fork == 0)
	{
		setenv("QUERY_STRING", cgiargs, 1);
		if (dup2(fd, STDOUT_FILENO) < 0)
		{
			fprintf(stderr, "dup2 error\n");
			return;
		}
		char* emptylist[] = {};
		if (execve(filename, emptylist, environ) < 0)
		{
			fprintf(stderr, "execve error: execve %s failed.\n", filename);
			return;
		}
	}
	if (waitpid(-1, NULL, 0) < 0)
	{
		fprintf(stderr, "waitpid error\n");
		return;
	}
}

void clientError(int fd, Rio& rio, const char* cause, const char* error_num,
	             const char* short_message, const char* long_message)
{
	std::vector<char> buf(MAXLINE);
	std::vector<char> body(MAXBUFF);
	sprintf(&body[0], "<html><title>Error</title>");
	sprintf(&body[0], "%s<body bgcolor=""ffffff"">\r\n", &body[0]);
	sprintf(&body[0], "%s%s: %s\r\n", &body[0], error_num, short_message);
	sprintf(&body[0], "%s<p>%s: %s\r\n", &body[0], long_message, cause);
	sprintf(&body[0], "%s<hr><em>The Web Server</em>\r\n", &body[0]);

	sprintf(&buf[0], "HTTP/1.0 %s %s\r\n", error_num, short_message);
	rio.writen(&buf[0], strlen(&buf[0]));
	sprintf(&buf[0], "Content-type: text/html\r\n");
	rio.writen(&buf[0], strlen(&buf[0]));
	sprintf(&buf[0], "Content-length: %d\r\n\r\n", strlen(&body[0]));
	rio.writen(&buf[0], strlen(&buf[0]));
	rio.writen(&body[0], strlen(&body[0]));
}
