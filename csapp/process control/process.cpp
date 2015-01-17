#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

void UnixError(const char* message)
{
	fprintf(stderr, "%s: %s\n", message, strerror(errno));
	exit(0);
}

pid_t Fork()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		UnixError("fork error");
	}
	return pid;
}

unsigned int snooze(unsigned int second)
{
	unsigned int num = sleep(second);
	printf("Slept %d of %d\n", second - num, second);
	return num;
}

void test1()
{
	printf("%d %d\n", getpid(), getppid());
}

void test2()
{
	pid_t pid = Fork();
	int x = 0;
	if (!pid)
	{
		x = 1;
		printf("child: %d\n", x);
		exit(0);
	}
	x = -1;
	printf("parent: %d\n", x);
}

void test3()
{
	pid_t pid = Fork();
	if (!pid)
	{
		printf("child!\n");
		exit(0);
	}
	else
	{
		waitpid(-1, NULL, 0);
		printf("parent\n");
	}
	printf("end\n");
}

void test4()
{
	int state;
	pid_t pid;
	for (int i = 0; i < 2; ++i)
	{
		if ((pid = Fork()) == 0)
		{
			exit(100 + i);
		}
	}
	while ((pid = waitpid(-1, &state, 0)) > 0)
	{
		if (WIFEXITED(state))
		{
			printf("child %d terminated normally with exit state = %d\n", pid, WEXITSTATUS(state));
		}
		else
		{
			printf("child %d terminated abnormally\n", pid);
		}
	}
	if (errno != ECHILD)
	{
		UnixError("waitpid error!");
	}
}

void test5()
{
	int state;
	pid_t pid[2];
	pid_t wait_pid;
	for (int i = 0; i < 2; ++i)
	{
		if ((pid[i] = Fork()) == 0)
		{
			exit(100 + i);
		}
	}
	for (int i = 0; (wait_pid = waitpid(pid[i], &state, 0)) > 0; ++i)
	{
		if (WIFEXITED(state))
		{
			printf("child %d terminated normally with exit state = %d\n", wait_pid, WEXITSTATUS(state));
		}
		else
		{
			printf("child %d terminated abnormally\n", wait_pid);
		}
	}
	if (errno != ECHILD)
	{
		UnixError("waitpid error!");
	}
}

int main(int argc, char const *argv[])
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	snooze(2);
	return 0;
}
