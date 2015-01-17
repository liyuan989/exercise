#include "ProcessBase.h"

#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>

namespace blink
{

namespace processes
{

pid_t getpid()
{
	return ::getpid();
}

pid_t getppid()
{
	return ::getppid();
}

pid_t fork()
{
	pid_t val = ::fork();
	if (val < 0)
	{
		fprintf(stderr, "fork error: %s\n", strerror(errno));
	}
	return val;
}

pid_t waitpid(pid_t pid, int* status, int options)
{
	pid_t val = ::waitpid(pid, status, options);
	if (val < 0)
	{
		if (errno == EINTR)
		{
			fprintf(stderr, "pidwait error: %s\n", strerror(errno));
		}
	}
	return val;
}

pid_t wait(int* status)
{
	pid_t val = ::wait(status);
	if (val < 0)
	{
		if (errno == EINTR)
		{
			fprintf(stderr, "wait error: %s\n", strerror(errno));
		}
	}
	return val;
}

int execve(const char* filename, char* const argv[], char* const envp[])
{
	int val = ::execve(filename, argv, envp);
	if (val < 0)
	{
		fprintf(stderr, "execve error: %s\n", strerror(errno));
	}
	return val;
}

pid_t getpgrp()
{
	return ::getpgrp();
}

int setpgid(pid_t pid, pid_t pgid)
{
	int val = ::setpgid(pid, pgid);
	if (val < 0)
	{
		fprintf(stderr, "setpgid error: %s\n", strerror(errno));
	}
	return val;
}

int kill(pid_t pid, int sig)
{
	int val = ::kill(pid, sig);
	if (val < 0)
	{
		fprintf(stderr, "kill error: %s\n", strerror(errno));
	}
	return val;
}

unsigned int alarm(unsigned int secs)
{
	return ::alarm(secs);
}

sighandler_t signal(int signum, sighandler_t handler)
{
	return ::signal(signum, handler);
}

sighandler_t signalRestart(int signum, sighandler_t handler)
{
	struct sigaction old_action;
	struct sigaction action;
	action.sa_flags = SA_RESTART;
	action.sa_handler = handler;
	processes::sigemptyset(&action.sa_mask);
	processes::sigaction(signum, &action, &old_action);
	return old_action.sa_handler;
}

int sigaction(int signum, struct sigaction* act, struct sigaction* oldact)
{
	int val = ::sigaction(signum, act, oldact);
	if (val < 0)
	{
		fprintf(stderr, "sigaction error: %s\n", strerror(errno));
	}
	return val;
}

int sigprocmask(int how, const sigset_t* set, sigset_t* oldset)
{
	int val = ::sigprocmask(how, set, oldset);
	if (val < 0)
	{
		fprintf(stderr, "sigprocmask error: %s\n", strerror(errno));
	}
	return val;
}

int sigemptyset(sigset_t* set)
{
	int val = ::sigemptyset(set);
	if (val < 0)
	{
		fprintf(stderr, "sigemptyset error: %s\n", strerror(errno));
	}
	return val;
}

int sigfillset(sigset_t* set)
{
	int val = ::sigfillset(set);
	if (val < 0)
	{
		fprintf(stderr, "sigfillset error: %s\n", strerror(errno));
	}
	return val;
}

int sigaddset(sigset_t* set, int signum)
{
	int val = ::sigaddset(set, signum);
	if (val < 0)
	{
		fprintf(stderr, "sigaddset error: %s\n", strerror(errno));
	}
	return val;
}

int sigdelset(sigset_t* set, int signum)
{
	int val = ::sigdelset(set, signum);
	if (val < 0)
	{
		return val;
	}
	return val;
}

int sigismember(const sigset_t* set, int signum)
{
	int val = ::sigismember(set, signum);
	if (val < 0)
	{
		fprintf(stderr, "sigismember error: %s\n", strerror(errno));
	}
	return val;
}

}  // namespace processes

}  // namespace blink
