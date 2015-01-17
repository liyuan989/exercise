#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

void* Mmap(void* start, size_t length, int prot, int flags, int fd, off_t offset)
{
	void* address;
	if ((address = mmap(start, length, prot, flags, fd, offset)) == reinterpret_cast<void*>(-1))
	{
		fprintf(stderr, "%s: %s\n", "mmap error", strerror(errno));
		exit(0);
	}
	return address;
}

int Open(char* filename, int flags)
{
	int num;
	if ((num = open(filename, flags)) == -1)
	{
		fprintf(stderr, "%s: %s\n", "open error", strerror(errno));
		exit(0);
	}
	return num;
}

int Close(int fd)
{
	int val;
	if ((val = close(fd)) == -1)
	{
		fprintf(stderr, "%s: %s\n", "close error", strerror(errno));
		exit(0);
	}
	return val;
}

ssize_t Write(int fd, const void* buf, size_t n)
{
	int num;
	if ((num = write(fd, buf, n)) == -1)
	{
		fprintf(stderr, "%s: %s\n", "write error", strerror(errno));
		exit(0);
	}
	return num;
}

void MmapCopy(int fd, size_t length)
{
	void* bufp = Mmap(NULL, length, PROT_WRITE, MAP_PRIVATE, fd, 0);
    Write(STDOUT_FILENO, bufp, 10);
    munmap(bufp, length);
}

int main(int argc, char const *argv[])
{
	struct stat states;
	int fd = Open(const_cast<char*>("1"), O_RDONLY);
	fstat(fd, &states);
	MmapCopy(fd, states.st_size);
	Close(fd);
	return 0;
}
