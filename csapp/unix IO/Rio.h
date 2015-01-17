#ifndef __RIO_H__
#define __RIO_H__

#include <unistd.h>

#include <vector>

namespace ly
{

enum
{
	RIO_BEGIN = SEEK_SET,
	RIO_CURRENT = SEEK_CUR,
	RIO_END = SEEK_END
};

class Rio
{
public:
	Rio(int fd, size_t buffsize = 8192)
		: rio_fd(fd), rio_cnt(0), rio_buffsize(buffsize), rio_buf(rio_buffsize), rio_bufptr(&rio_buf[0])
	{
	}

	void setFd(int fd)
	{
		rio_fd = fd;
	}

	void setBuffsize(size_t n);
	ssize_t readn(void* usrbuf, size_t n);
	ssize_t writen(void* usrbuf, size_t n);
	ssize_t readlineb(void* usrbuf, size_t maxlen);
	ssize_t readnb(void* usrbuf, size_t n);
	off_t lseekn(off_t offset, int whence);

private:
	Rio(const Rio&);
	Rio& operator=(const Rio&);
	ssize_t rioRead(char* usrbuf, size_t n);

	int                rio_fd;
	int                rio_cnt;
	size_t             rio_buffsize;
	std::vector<char>  rio_buf;
	char*              rio_bufptr;
};

}

#endif
