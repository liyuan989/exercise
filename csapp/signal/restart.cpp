#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

sigjmp_buf buf;

typedef void (*handler_t)(int);

void UnixError(const char* message)
{
	fprintf(stderr, "%s: %s\n", message, strerror(errno));
	exit(0);
}

pid_t Fork()
{
	pid_t pid = fork();
	if (pid < 0)
	{
		UnixError("fork error");
	}
	return pid;
}

void SignalHandler(int sig)
{
	siglongjmp(buf, 1);
}

handler_t Signal(int signum, handler_t handler)
{
	struct sigaction action;
	struct sigaction old_action;
	action.sa_handler = SignalHandler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	if (sigaction(signum, &action, &old_action) < 0)
	{
		UnixError("sigaction error");
	}
	return old_action.sa_handler;
}

int main(int argc, char const *argv[])
{
	Signal(SIGINT, SignalHandler);
	int rc = sigsetjmp(buf, SIGINT);
	if (rc == 1)
	{
		printf("Restarting...\n");
	}
	while (1)
	{
		printf("Processing...\n");
		sleep(1);
	}
	return 0;
}
