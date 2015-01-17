#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd1 = open("2", O_RDWR);
	int fd_out = dup(STDOUT_FILENO);
	int val = dup2(fd1, STDOUT_FILENO);

	printf("val = %d\n", val);
	fprintf(stdout, "hello boy!\n");
	fprintf(stdout, "hello girl!\n");
	fflush(stdout);

	dup2(fd_out, STDOUT_FILENO);
	printf("fd_out = %d\n", fd_out);
	printf("111111\n");
	return 0;
}
