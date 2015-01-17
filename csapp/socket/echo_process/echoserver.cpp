#include "Rio.h"
#include "SocketBase.h"

#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace blink;

void echo(int connectfd, const char* addrp);
void collectSubprocess(int signum);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	if (signal(SIGCHLD, collectSubprocess) == SIG_ERR)
	{
		fprintf(stderr, "signal error\n");
		exit(0);
	}
	int listenfd = sockets::openListenFd(atoi(argv[1]));
	if (listenfd < 0)
	{
		exit(0);
	}
	int connectfd;
	char addrp[20];
	struct sockaddr_in clientaddr;
	int cilentlen = sizeof(clientaddr);
	while (true)
	{
		connectfd = sockets::accept(listenfd, sockets::sockaddr_cast(&clientaddr), &cilentlen);
		if (connectfd >= 0)
		{
			sockets::inet_ntop(AF_INET, &clientaddr.sin_addr, addrp, sizeof(addrp));
			printf("server connected to %s\n", addrp);
			if (fork() == 0)
			{
				echo(connectfd, addrp);
				exit(0);
			}
			sockets::close(connectfd);
		}
	}
	return 0;
}

void echo(int connectfd, const char* addrp)
{
	std::vector<char> buf(1024*64);
	size_t bufsize = buf.size();
	size_t n;
	Rio rio(connectfd, 1024*1024);
	while ((n = rio.readlineb(&buf[0], bufsize)) != 0)
	{
		printf("server received %d bytes\n", n);
		rio.writen(&buf[0], n);
	}
	if (sockets::close(connectfd) == 0)
	{
		fprintf(stderr, "server closed from %s\n", addrp);
	}
}

void collectSubprocess(int signum)
{
	while (waitpid(-1, NULL, WNOHANG | WUNTRACED) > 0)
	{
		;
	}
}
