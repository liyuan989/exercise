#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>

void HexToDd(const char* ipaddr)
{
	unsigned int temp = ntohl(atof(ipaddr));
	struct in_addr addr_ = {temp};
	const char* dd_ipaddr = inet_ntoa(addr_);
	printf("%s\n", dd_ipaddr);
}

void DdToHex(const char* ipaddr)
{
	struct in_addr addr_;
	if (inet_aton(ipaddr, &addr_) == -1)
	{
		fprintf(stderr, "inet_aton error\n");
		return;
	}
	printf("0x%x\n", htonl(addr_.s_addr));
}

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		return 0;
	}
	//HexToDd(argv[1]);
	DdToHex(argv[1]);
	return 0;
}
