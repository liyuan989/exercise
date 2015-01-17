#include "Rio.h"
#include "SocketBase.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace blink;

void echo(int connectfd)
{
	char buf[4096];
	size_t n;
	Rio rio(connectfd);
	while ((n = rio.readlineb(buf, 4096)) != 0)
	{
		printf("server received %d bytes\n", n);
		rio.writen(buf, n);
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		return 0;
	}

	int listenfd = sockets::openListenFd(atoi(argv[1]));
	if (listenfd < 0)
	{
		return 0;
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
			echo(connectfd);
			if (sockets::close(connectfd) >= 0)
			{
				fprintf(stderr, "closed connect: from %s\n", addrp);
			}
		}
	}
	return 0;
}
