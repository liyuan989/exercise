#include "Rio.h"

#include <unistd.h>
#include <fcntl.h>

#include <vector>
#include <stdio.h>
#include <string.h>
#include <errno.h>

namespace ly
{

void Rio::setBuffsize(size_t n)
{
	rio_buf.resize(n);
}

ssize_t Rio::readn(void* usrbuf, size_t n)
{
	if (n > rio_buffsize)
	{
		fprintf(stderr, "error: run out of buffsize range\n");
		return -1;
	}
	ssize_t n_left = n;
	ssize_t n_read;
	char* bufp = static_cast<char*>(usrbuf);

	while (n_left > 0)
	{
		if ((n_read = ::read(rio_fd, bufp, n_left)) < 0)
		{
			if (errno == EINTR)
			{
				n_read = 0;
			}
			else
			{
				return -1;
			}
		}
		else if (n_read == 0)
		{
			break;
		}
		n_left -= n_read;
		bufp += n_read;
	}
	return n - n_left;
}

ssize_t Rio::writen(void* usrbuf, size_t n)
{
	if (n > rio_buffsize)
	{
		fprintf(stderr, "error: run out of buffsize range\n");
		return -1;
	}
	ssize_t n_left = n;
	ssize_t n_write;
	char* bufp = static_cast<char*>(usrbuf);

	while (n_left > 0)
	{
		if ((n_write = ::write(rio_fd, bufp, n_left)) <= 0)
		{
			if (errno == EINTR)
			{
				n_write = 0;
			}
			else
			{
				return -1;
			}
		}
		n_left -= n_write;
		bufp += n_write;
	}
	return n;
}

ssize_t Rio::readlineb(void* usrbuf, size_t maxlen)
{
	if (maxlen > rio_buffsize)
	{
		fprintf(stderr, "error: run out of buffsize range\n");
		return -1;
	}
	size_t n;
	ssize_t rc;
	char c;
	char* bufp = static_cast<char*>(usrbuf);

	for (n = 1; n < maxlen; ++n)
	{
		if ((rc = rioRead(&c, 1)) == 1)
		{
			*bufp = c;
			++bufp;
			if (c == '\n')
			{
				break;
			}
		}
		else if (rc == 0)
		{
			if (n == 1)
			{
				return 0;
			}
			else
			{
				break;
			}
		}
		else
		{
			return -1;
		}
	}
	*bufp = 0;
	return n;
}

ssize_t Rio::readnb(void* usrbuf, size_t n)
{
	if (n > rio_buffsize)
	{
		fprintf(stderr, "error: run out of buffsize range\n");
		return -1;
	}
	ssize_t n_left = n;
	ssize_t n_read;
	char* bufp = static_cast<char*>(usrbuf);

	while (n_left > 0)
	{
		if ((n_read = rioRead(bufp, n_left)) < 0)
		{
			if (errno == EINTR)
			{
				n_read = 0;
			}
			else
			{
				return -1;
			}
		}
		else if (n_read == 0)
		{
			break;
		}
		n_left -= n_read;
		bufp += n_read;
	}
	return n - n_left;
}

ssize_t Rio::rioRead(char* usrbuf, size_t n)
{
	if (n > rio_buffsize)
	{
		fprintf(stderr, "error: run out of buffsize range\n");
		return -1;
	}

	while (rio_cnt <= 0)
	{
		if ((rio_cnt = read(rio_fd, rio_bufptr, sizeof(rio_buf))) < 0)
		{
			if (errno != EINTR)
			{
				return -1;
			}
		}
		else if (rio_cnt == 0)
		{
			return 0;
		}
		else
		{
			rio_bufptr = &rio_buf[0];
		}
	}

	int count = n;
	if (rio_cnt < static_cast<int>(n))
	{
		count = rio_cnt;
	}
	memcpy(usrbuf, rio_bufptr, count);
	rio_bufptr += count;
	rio_cnt -= count;
	return count;
}

off_t Rio::lseekn(off_t offset, int whence)
{
	return ::lseek(rio_fd, offset, whence);
}

}  //namespace ly
