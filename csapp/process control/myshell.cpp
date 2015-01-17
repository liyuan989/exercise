#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 128
#define MAXARGS 10

int CmdlineParse(char* cmdline, char** argv)
{
	cmdline[strlen(cmdline) - 1] = ' ';
	while (*cmdline && (*cmdline == ' '))
	{
		++cmdline;
	}
	char* dilimiter;
	int i;
	for (i = 0; (dilimiter = strchr(cmdline, ' ')); ++i, cmdline = dilimiter + 1)
	{
		argv[i] = cmdline;
		*dilimiter = '\0';
		while (*cmdline && (*cmdline == '0'))
		{
			++cmdline;
		}
	}
	argv[i] = '\0';
	if (!i)
	{
		return 1;
	}
	if (*argv[i - 1] == '&')
	{
		return 1;
	}
	return 0;
}

int BuildIn(char** argv)
{
	if (!strcmp(argv[0], "quit"))
	{
		exit(0);
	}
	if (!strcmp(argv[0], "&"))
	{
		return 1;
	}
	return 0;
}

void Evaluate(char* cmdline)
{
	char* argv[MAXARGS];
	char buffer[MAXLINE];
	pid_t pid;
	strcpy(buffer, cmdline);
	int flag = CmdlineParse(buffer, argv);
	if (!argv[0])
	{
		return;
	}
	if (!BuildIn(argv))
	{
		pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
		}
		if (!pid)
		{
			if (execve(argv[0], argv, environ) < 0)
			{
				printf("%s: Command not found.\n", argv[0]);
				exit(0);
			}
		}
	}
	if (!flag)
	{
		int status;
		if (waitpid(pid, &status, 0) < 0)
		{
			fprintf(stderr, "%s: %s\n", "waitpid error", strerror(errno));
		}
		else
		{
			//printf("%d %s\n", pid, cmdline);
		}
	}
	return;
}

void ExecuteShell()
{
	char cmdline[MAXLINE];
	while (1)
	{
		printf("liyuan@liyuan:~# ");
		fgets(cmdline, MAXLINE, stdin);
		if (feof(stdin))
		{
			return;
		}
		Evaluate(cmdline);
	}
	return;
}

int main(int argc, char const *argv[])
{
	ExecuteShell();
	return 0;
}
