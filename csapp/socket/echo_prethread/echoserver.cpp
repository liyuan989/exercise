#include "Sbuf.h"
#include "Rio.h"
#include "SocketBase.h"
#include "ThreadBase.h"
#include "MutexLock.h"

#include <unistd.h>

#include <tr1/memory>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace blink;

namespace
{

typedef std::tr1::shared_ptr<std::pair<int, std::string> > Client_info;
MutexLock mutex;
int byte_count = 0;

}

void echo(int connectfd, const char* addrp);
void* thread(void* args);

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	int listenfd = sockets::openListenFd(atoi(argv[1]));
	if (listenfd < 0)
	{
		exit(0);
	}
	int connectfd;
	pthread_t tid;
	char addrp[20];
	struct sockaddr_in clientaddr;
	int clientlen = sizeof(clientaddr);
	Sbuf<Client_info> sbuf;
	for (int i = 0; i < 3; ++i)
	{
		threads::pthread_create(&tid, NULL, thread, static_cast<void*>(&sbuf));
	}
	while (true)
	{
		connectfd = sockets::accept(listenfd, sockets::sockaddr_cast(&clientaddr), &clientlen);
		if (connectfd >= 0)
		{
			sockets::inet_ntop(AF_INET, &clientaddr.sin_addr, addrp, sizeof(addrp));
			printf("server connected to %s\n", addrp);
			sbuf.insert(Client_info(new std::pair<int, std::string>(connectfd, std::string(addrp))));
		}
	}
	return 0;
}

void* thread(void* args)
{
	threads::pthread_detach(threads::pthread_self());
	Sbuf<Client_info>* sbufp = static_cast<Sbuf<Client_info>*>(args);
	while (true)
	{
		Client_info client_info = sbufp->remove();
		echo(client_info->first, client_info->second.c_str());
	}
	return NULL;
}

void echo(int connectfd, const char* addrp)
{
	std::vector<char> buf(1024*64);
	size_t bufsize = buf.size();
	size_t n;
	Rio rio(connectfd, 1024*1024);
	while ((n = rio.readlineb(&buf[0], bufsize)) != 0)
	{
		mutex.lock();
		byte_count += n;
		printf("server received %d bytes (%d total)\n", n, byte_count);
		mutex.unlock();
		rio.writen(&buf[0], n);
	}
	if (sockets::close(connectfd) == 0)
	{
		fprintf(stderr, "server closed from %s\n", addrp);
	}
}
