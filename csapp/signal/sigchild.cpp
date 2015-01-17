#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
	pid_t pid;
	while ((pid = waitpid(-1, NULL, 0)) > 0)
	{
		printf("Handler reaped child %d\n", pid);
	}
	if (errno != ECHILD)
	{
		UnixError("waitpid error");
	}
	sleep(2);
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
	char buffer[128];
	if (Signal(SIGCHLD, SignalHandler) == SIG_ERR)
	{
		UnixError("signal error");
	}
	for (int i = 0; i < 3; ++i)
	{
		if (Fork() == 0)
		{
			printf("Hello from child %d\n", getpid());
			sleep(1);
			exit(0);
		}
	}
	if (read(STDIN_FILENO, buffer, sizeof(buffer)) < 0)
	{
			UnixError("read error");
	}
	printf("Parent process input\n");
	while (1)
	{
	}
	return 0;
}
