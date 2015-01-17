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
	static int count = 0;
	if (count < 4)
	{
		printf("beep!\n");
		alarm(1);
		++count;
	}
	else
	{
		printf("boom!!!\n");
		exit(0);
	}
}

int main(int argc, char const *argv[])
{
	signal(SIGALRM, SignalHander);
	alarm(1);
	while (1)
	{
	}
	return 0;
}
