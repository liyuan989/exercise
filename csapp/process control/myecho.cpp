#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

void MyEcho(int argc, char const *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		printf("argc[%d]: %s\n", i, argv[i]);
	}
	char** envp = environ;
	for (int i = 0; envp[i]; ++i)
	{
		printf("envp[%d]: %s\n", i, envp[i]);
	}
}

int main(int argc, char const *argv[])
{
	MyEcho(argc, argv);
	return 0;
}
