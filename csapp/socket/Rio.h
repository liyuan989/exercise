#ifndef __BLINK_RIO_H__
#define __BLINK_RIO_H__

#include "Nocopyable.h"

#include <unistd.h>

#include <vector>

namespace blink
{

enum
{
	RIO_BEGIN = SEEK_SET,
	RIO_CURRENT = SEEK_CUR,
	RIO_END = SEEK_END
};

class Rio : Nocopyable
{
public:
	Rio(int fd, size_t buffsize = 8192)
		: fd_(fd), count_(0), buffsize_(buffsize), buf_(buffsize_), bufptr_(&buf_[0])
	{
	}

	void setFd(int fd)
	{
		fd_ = fd;
	}

	void setBuffsize(size_t n);
	ssize_t readn(void* usrbuf, size_t n);
	ssize_t writen(void* usrbuf, size_t n);
	ssize_t readlineb(void* usrbuf, size_t maxlen);
	ssize_t readnb(void* usrbuf, size_t n);
	off_t lseekn(off_t offset, int whence);

private:
	ssize_t rioRead(char* usrbuf, size_t n);

	int                fd_;
	int                count_;
	size_t             buffsize_;
	std::vector<char>  buf_;
	char*              bufptr_;
};

}  //namespace blink

#endif
