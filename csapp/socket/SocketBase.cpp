#include "SocketBase.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

namespace blink
{

namespace sockets
{

struct sockaddr* sockaddr_cast(struct sockaddr_in* addr)
{
	return static_cast<struct sockaddr*>(static_cast<void*>(addr));
}

const struct sockaddr* sockaddr_cast(const struct socket_in* addr)
{
	return static_cast<const struct sockaddr*>(static_cast<const void*>(addr));
}

struct sockaddr_in* sockaddr_in_cast(struct sockaddr* addr)
{
	return static_cast<struct sockaddr_in*>(static_cast<void*>(addr));
}

const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr)
{
	return static_cast<const struct sockaddr_in*>(static_cast<const void*>(addr));
}

unsigned long htonl(unsigned long hostlong)
{
	return ::htonl(hostlong);
}

unsigned short htons(unsigned short hostshort)
{
	return ::htons(hostshort);
}

unsigned long ntohl(unsigned long netlong)
{
	return ::ntohl(netlong);
}

unsigned short ntohs(unsigned short netshort)
{
	return ::ntohs(netshort);
}

int inet_pton(int family, const char* str, struct in_addr* addr)
{
	return ::inet_pton(family, str, static_cast<void*>(addr));
}

const char* inet_ntop(int family, const struct in_addr* addr, char* str, size_t len)
{
	return ::inet_ntop(family, static_cast<const void*>(addr), str, len);
}

struct hostent* gethostbyname(const char* name)
{
	struct hostent* val = ::gethostbyname(name);
	if (val == NULL)
	{
		fprintf(stderr, "gethostbyname error: %s\n", ::hstrerror(h_errno));
	}
	return val;
}

struct hostent* gethostbyaddr(const char* addr, int len, int type)
{
	struct hostent* val = ::gethostbyaddr(addr, len, type);
	if (val == NULL)
	{
		fprintf(stderr, "gethostbyaddr error: %s\n", ::hstrerror(h_errno));
	}
	return val;
}

int getaddrinfo(const char* hostname, const char* service, const struct addrinfo* hints, struct addrinfo** result)
{
	int val = ::getaddrinfo(hostname, service, hints, result);
	if (val != 0)
	{
		fprintf(stderr, "getaddrinfo error: %s\n", ::gai_strerror(val));
	}
	return val;
}

int getnameinfo(const struct sockaddr* addr, socklen_t addrlen, char* host, socklen_t hostlen,
	            char* serv, socklen_t servlen, int flags)
{
	int val = ::getnameinfo(addr, addrlen, host, hostlen, serv, servlen, flags);
	if (val != 0)
	{
		fprintf(stderr, "getnameinfo error: %s\n", ::gai_strerror(val));
	}
	return val;
}

int socket(int domain, int type, int protocol)
{
	int val = ::socket(domain, type, protocol);
	if (val < 0)
	{
		fprintf(stderr, "socket error\n");
	}
	return val;
}

int connect(int sockfd, struct sockaddr* server_addr, int addrlen)
{
	int val = ::connect(sockfd, server_addr, addrlen);
	if (val < 0)
	{
		fprintf(stderr, "connect error\n");
	}
	return val;
}

int bind(int sockfd, struct sockaddr* my_addr, int addrlen)
{
	int val = ::bind(sockfd, my_addr, addrlen);
	if (val < 0)
	{
		fprintf(stderr, "bind error\n");
	}
	return val;
}

int listen(int sockfd, int backlog)
{
	char* ptr;
	if ((ptr = ::getenv("LISTENQ")) != NULL)
	{
		backlog = ::atoi(ptr);
	}
	int val = ::listen(sockfd, backlog);
	if (val < 0)
	{
		fprintf(stderr, "listen error\n");
	}
	return val;
}

int accept(int listenfd, struct sockaddr* addr, int* addrlen)
{
	int val = ::accept(listenfd, addr, static_cast<socklen_t*>(static_cast<void*>(addrlen)));
	if (val < 0)
	{
		fprintf(stderr, "accept error\n");
	}
	return val;
}

int read(int fd, void* buf, unsigned int n)
{
	return ::read(fd, buf, n);
}

int write(int fd, const void* buf, unsigned int n)
{
	return ::write(fd, buf, n);
}

int close(int fd)
{
	int val = ::close(fd);
	if (val < 0)
	{
		fprintf(stderr, "close error\n");
	}
	return val;
}

int openClientFd(char* hostname, int port)
{
	int clientfd = sockets::socket(AF_INET, SOCK_STREAM, 0);
	if (clientfd < 0)
	{
		return -1;
	}
	struct hostent* hostp;
	struct in_addr ipaddr;
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = sockets::htons(port);
	if (sockets::inet_pton(AF_INET, hostname, &ipaddr) != 1)
	{
		hostp = sockets::gethostbyname(hostname);
		if (hostp == NULL)
		{
			fprintf(stderr, "gethostbyname error: %s\n", ::hstrerror(h_errno));
			return -2;
		}
		memcpy(&serveraddr.sin_addr.s_addr, &hostp->h_addr_list[0], hostp->h_length);
	}
	else
	{
		memcpy(&serveraddr.sin_addr.s_addr, &ipaddr.s_addr, sizeof(ipaddr.s_addr));
	}
	if (sockets::connect(clientfd, sockets::sockaddr_cast(&serveraddr), sizeof(serveraddr)) < 0)
	{
		return -1;
	}
	return clientfd;
}

int openListenFd(int port)
{
	int listenfd = sockets::socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
	{
		return -1;
	}
	const int optval = 1;
	if (::setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, static_cast<const void*>(&optval), sizeof(int)) < 0)
	{
		fprintf(stderr, "setsockopt error\n");
		return -1;
	}
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = sockets::htons(static_cast<unsigned short>(port));
	serveraddr.sin_addr.s_addr = sockets::htonl(INADDR_ANY);
	if (sockets::bind(listenfd, sockets::sockaddr_cast(&serveraddr), sizeof(serveraddr)) < 0)
	{
		return -1;
	}
	if (sockets::listen(listenfd, ::atoi("LISTENQ")) < 0)
	{
		return -1;
	}
	return listenfd;
}

}  // namespace sockets

}  // namespace blink
