#include "Rio.h"
#include "SocketBase.h"

#include <vector>
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
	Rio rio(clientfd, 1024*1024);
	std::vector<char> buf(1024*64);
	int buflen = buf.size();
	while (Fgets(&buf[0], buflen, stdin) != NULL)
	{
		rio.writen(&buf[0], strlen(&buf[0]));
		rio.readlineb(&buf[0], buflen);
		fputs(&buf[0], stdout);
	}
	sockets::close(clientfd);
	return 0;
}
