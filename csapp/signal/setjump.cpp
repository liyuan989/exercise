#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

jmp_buf buf;
int error1 = 0;
int error2 = 1;

void bar()
{
	if (error2)
	{
		longjmp(buf, 2);
	}
}

void foo()
{
	if (error1)
	{
		longjmp(buf, 1);
	}
	bar();
}

int main(int argc, char const *argv[])
{
	int rc = setjmp(buf);
	if (rc == 0)
	{
		foo();
	}
	else if (rc == 1)
	{
		printf("Deteced an error1 condition in foo\n");
	}
	else if (rc == 2)
	{
		printf("Deteced an error2 condition in foo\n");
	}
	else
	{
		printf("Unknown error condition in foo\n");
	}
	return 0;
}
