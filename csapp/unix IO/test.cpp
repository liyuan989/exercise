#include "Rio.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#include <iostream>
#include <string.h>

using namespace ly;

int main(int argc, char const *argv[])
{
	int fd = open("1.txt", O_RDWR | O_APPEND);
	if (fd < 0)
	{
		std::cerr << "open error" << std::endl;
		return 0;
	}
	Rio rio(fd);

	char c1[15];
	memset(c1, 0, sizeof(c1));
	rio.readn(c1, 15);
	std::cout << c1 << std::endl;

	memset(c1, 0, sizeof(c1));
	rio.lseekn(0, RIO_BEGIN);
	rio.readnb(c1, 15);
	std::cout << c1 << std::endl;

	memset(c1, 0, sizeof(c1));
	rio.lseekn(0, RIO_BEGIN);
	int count = rio.readlineb(c1, 15);
	std::cout << c1 << std::endl;
	std::cout << "there is " << count << " words." << std::endl;

	char c2[] = "hey girl!";
	rio.setFd(1);
	rio.setBuffsize(4096);
	rio.writen(c2, sizeof(c2));

	return 0;
}
