#ifndef __BLINK_SOCKETBASE_H__
#define __BLINK_SOCKETBASE_H__

#include <netinet/in.h>
#include <netdb.h>

namespace blink
{

namespace sockets
{

unsigned long htonl(unsigned long hostlong);
unsigned short htons(unsigned short hostshort);
unsigned long ntohl(unsigned long netlong);
unsigned short ntohs(unsigned short netshort);

int inet_pton(int family, const char* str, struct in_addr* addr);
const char* inet_ntop(int family, const struct in_addr* addr, char* str, size_t len);

//  struct hostent
//  {
//  	char*   h_name;              /* official name of host */
//  	char**  h_aliases;           /* alias list */
//  	int     h_addrtype;          /* host address type */
//  	int     h_length;            /* length of address */
//  	char**  h_addr_list;         /* list of addresses */
//  };

struct hostent* gethostbyname(const char* name);  // thread unsafe
struct hostent* gethostbyaddr(const char* addr, int len, int type);  // thread unsafe

//  struct addrinfo
//  {
//      int               ai_flags;       /* AI_PASSIVE, AI_CANONNAME */
//      int               ai_family;      /* AF_xxx */
//      int               ai_socktype;    /* SOCK_xxx */
//      int               ai_protocol;    /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
//      socklen_t         ai_addrlen;     /* length of ai_addr */
//      char*             ai_canonname;   /* ptr to canonical name for host */
//      struct sockaddr*  ai_addr;        /* ptr to socket address structure */
//      struct addrinfo*  ai_next;        /* ptr to next structure in licked list */
//  };

int getaddrinfo(const char* hostname, const char* service, const struct addrinfo* hints, struct addrinfo** result);
int getnameinfo(const struct sockaddr* addr, socklen_t addrlen, char* host, socklen_t hostlen,
	            char* serv, socklen_t servlen, int flags);

//  struct sockaddr
//  {
//  　　unsigned short sa_family;    /* address family, AF_xxx */
//  　　char sa_data[14];            /* 14 bytes of protocol address */
//  };
//
//  struct sockaddr_in
//  {
//  	short int sin_family;        /* Address family */
//  	unsigned short int sin_port; /* Port number */
//  	struct in_addr sin_addr;     /* Internet address */
//  	unsigned char sin_zero[8];   /* Same size as struct sockaddr */
//  };
//
//  struct in_addr
//  {
//      unsigned int s_addr;         /* 32 bits */
//  };

struct sockaddr* sockaddr_cast(struct sockaddr_in* addr);
const struct sockaddr* sockaddr_cast(const struct socket_in* addr);
struct sockaddr_in* sockaddr_in_cast(struct sockaddr* addr);
const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr);

int socket(int domain, int type, int protocol);
int connect(int sockfd, struct sockaddr* server_addr, int addrlen);
int bind(int sockfd, struct sockaddr* my_addr, int addrlen);
int listen(int sockfd, int backlog);
int accept(int listenfd, struct sockaddr* addr, int* addrlen);
int read(int fd, void* buf, unsigned int n);
int write(int fd, const void* buf, unsigned int n);
int close(int fd);

int openClientFd(char* hostname, int port);
int openListenFd(int port);

}  // namespace sockets

}  // namespace blink

#endif
