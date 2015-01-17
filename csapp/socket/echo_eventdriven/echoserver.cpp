#include "Rio.h"
#include "SocketBase.h"
#include "Nocopyable.h"

#include <sys/select.h>
#include <unistd.h>

#include <tr1/memory>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace blink;

struct EventPool : Nocopyable
{
	typedef std::tr1::shared_ptr<Rio> RioPtr;

	int nready;
	int maxfd;
	fd_set read_set;
	fd_set ready_set;
	std::map<int, RioPtr> events;
	std::map<int, int> event_counts;
	std::map<int, std::string> ipaddrs;
	static int byte_count;
};

int EventPool::byte_count = 0;

void checkClient(EventPool& pool);

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

	EventPool pool;
	pool.nready = 0;
	pool.maxfd = listenfd;
	FD_ZERO(&pool.read_set);
	FD_SET(listenfd, &pool.read_set);

	int connectfd;
	char addrp[20];
	struct sockaddr_in clientaddr;
	int cilentlen = sizeof(clientaddr);
	while (true)
	{
		pool.ready_set = pool.read_set;
		pool.nready = select(pool.maxfd + 1, &pool.ready_set, 0, 0, 0);
		if (FD_ISSET(listenfd, &pool.ready_set))
		{
			--pool.nready;
			connectfd = sockets::accept(listenfd, sockets::sockaddr_cast(&clientaddr), &cilentlen);
			if (connectfd >= 0)
			{
				sockets::inet_ntop(AF_INET, &clientaddr.sin_addr, addrp, sizeof(addrp));
				printf("server connected to %s\n", addrp);
				pool.events.insert(std::make_pair(connectfd, new Rio(connectfd)));
				pool.event_counts.insert(std::make_pair(connectfd, 0));
				pool.ipaddrs.insert(std::make_pair(connectfd, std::string(addrp)));
				FD_SET(connectfd, &pool.read_set);
				if (connectfd > pool.maxfd)
				{
					pool.maxfd = connectfd;
				}
			}
		}
		checkClient(pool);
	}
	return 0;
}

void checkClient(EventPool& pool)
{
	for (std::map<int, EventPool::RioPtr>::iterator iter = pool.events.begin(); iter != pool.events.end(); ++iter)
	{
		if (FD_ISSET((*iter).first, &pool.ready_set))
		{
			--pool.nready;
			std::vector<char> buf(1024);
			int n;
			if ((n = (*iter).second->readlineb(&buf[0], buf.size())) != 0)
			{
				EventPool::byte_count += n;
				pool.event_counts[(*iter).first] += n;
				printf("Server recieved %d bytes (%d on %s, %d totals)\n", n, pool.event_counts[(*iter).first],
				       pool.ipaddrs[(*iter).first].c_str(), EventPool::byte_count);
				fflush(stdout);
				(*iter).second->writen(&buf[0], strlen(&buf[0]));
			}
			else
			{
				if (sockets::close((*iter).first) >= 0)
				{
					fprintf(stderr, "closed connect: from %s\n", pool.ipaddrs[(*iter).first].c_str());
				}
				FD_CLR((*iter).first, &pool.read_set);
				pool.events.erase(iter);
			}
		}
	}
}
