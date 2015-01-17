#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		fprintf(stderr, "error: no other param.\n");
		return 0;
	}
	struct in_addr addr;
	struct hostent* hostp;
	if (inet_aton(argv[1], &addr) == 1)
	{
		hostp = gethostbyaddr(reinterpret_cast<const char*>(&addr), sizeof(addr.s_addr), AF_INET);
		if (hostp == NULL)
		{
			fprintf(stderr, "gethostbyaddr error: %s\n", strerror(h_errno));
			return 0;
		}
	}
	else
	{
		hostp = gethostbyname(argv[1]);
		if (hostp == NULL)
		{
			fprintf(stderr, "gethostbyname error: %s\n", strerror(h_errno));
			return 0;
		}
	}
	printf("official hostname: %s\n", hostp->h_name);
	for (char** p = hostp->h_aliases; *p != NULL; ++p)
	{
		printf("aliase: %s\n", *p);
	}
	for (char** p = hostp->h_addr_list; *p != NULL ; ++p)
	{
		addr.s_addr = (reinterpret_cast<struct in_addr*>(*p))->s_addr;
		printf("address: %s\n", inet_ntoa(addr));
	}
	return 0;
}
