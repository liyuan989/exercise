#include "Rio.h"
#include "SocketBase.h"

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

using namespace blink;

char* Fgets(char* buf, int buffsize, FILE* stream)
{
	char* val = fgets(buf, buffsize, stream);
	if (val == NULL)
	{
		fprintf(stderr, "fgets error: %s\n", strerror(errno));
	}
	return val;
}

int Fputs(const char* ptr, FILE* stream)
{
	int val = fputs(ptr, stream);
	if (val < 0)
	{
		fprintf(stderr, "fputs error: %s\n", strerror(errno));
	}
	return val;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		return 0;
	}
	int clientfd = sockets::openClientFd(argv[1], atoi(argv[2]));
	if (clientfd < 0)
	{
		exit(1);
	}
	Rio rio(clientfd);
	char buf[4096];
	int buflen = sizeof(buf);
	while (Fgets(buf, 4096, stdin) != NULL)
	{
		rio.writen(buf, strlen(buf));
		rio.readlineb(buf, buflen);
		fputs(buf, stdout);
	}
	sockets::close(clientfd);
	return 0;
}
