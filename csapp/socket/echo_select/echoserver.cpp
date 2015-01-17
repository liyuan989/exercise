#include "Rio.h"
#include "SocketBase.h"

#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#include <vector>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace blink;

typedef void (*sighandler)(int);

void echo(int connectfd, const char* addrp);
void collectSubprocess(int signum);
void command();
sighandler setSignal(int signum, sighandler handler);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	if (setSignal(SIGCHLD, collectSubprocess) == SIG_ERR)
	{
		exit(0);
	}
	int listenfd = sockets::openListenFd(atoi(argv[1]));
	if (listenfd < 0)
	{
		exit(0);
	}

	int connectfd;
	int select_val;
	char addrp[20];

	struct sockaddr_in clientaddr;
	int cilentlen = sizeof(clientaddr);

	fd_set read_set;
	fd_set ready_set;
	FD_ZERO(&read_set);
	FD_SET(listenfd, &read_set);
	FD_SET(STDIN_FILENO, &read_set);

	struct timeval set_time;
	set_time.tv_sec = 0;
	set_time.tv_usec = 0;
	while (true)
	{
		ready_set = read_set;
		if ((select_val = select(listenfd + 1, &ready_set, NULL, NULL, &set_time)) > 0)
		{
			if (FD_ISSET(listenfd, &ready_set))
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
			if (FD_ISSET(STDIN_FILENO, &ready_set))
			{
				if (fork() == 0)
				{
					command();
					exit(0);
				}
			}
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

void command()
{
	std::vector<char> buf(1024);
	fgets(&buf[0], 1024, stdin);
	printf("%s", &buf[0]);
	fflush(stdin);
}

sighandler setSignal(int signum, sighandler handler)
{
	struct sigaction old_action;
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	if (sigaction(signum, &action, &old_action) < 0)
	{
		fprintf(stderr, "Signal error: %s\n", strerror(errno));
		return SIG_ERR;
	}
	return old_action.sa_handler;
}
