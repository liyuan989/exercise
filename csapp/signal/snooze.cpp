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
}

unsigned int snooze(unsigned int second)
{
	if (signal(SIGINT, SignalHander) == SIG_ERR)
	{
		fprintf(stderr, "%s: %s\n", "set signal hander error", strerror(errno));
		exit(0);
	}
	unsigned int num = sleep(second);
	printf("Slept %d of %d\n", second - num, second);
	return num;
}

int main(int argc, char const *argv[])
{
	snooze(10);
	return 0;
}
