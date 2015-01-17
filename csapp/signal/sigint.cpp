#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void SignalHander(int sig)
{
	printf("caught SIGINT!\n");
	exit(0);
}

int main(int argc, char const *argv[])
{
	if (signal(SIGINT, SignalHander) == SIG_ERR)
	{
		fprintf(stderr, "%s: %s", "set signal hander error", strerror(errno));
		exit(0);
	}
	pause();
	return 0;
}
