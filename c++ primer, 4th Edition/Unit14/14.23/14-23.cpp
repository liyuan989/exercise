#include <iostream>
#include <string>

class CheckedPtr
{
public:
	CheckedPtr(int *b, int *e): beg(b), end(e), curr(b) {}
	CheckedPtr& operator++();
	CheckedPtr operator++(int);
	CheckedPtr& operator--();
	CheckedPtr operator--(int);
	int& operator[](const size_t index);
	const int& operator[](const size_t index) const;
	int& operator*();
	const int& operator*() const;

	inline friend bool operator==(const CheckedPtr &obj1, const CheckedPtr &obj2);
	inline friend bool operator!=(const CheckedPtr &obj1, const CheckedPtr &obj2);
	inline friend bool operator<(const CheckedPtr &obj1, const CheckedPtr &obj2);
	friend CheckedPtr operator+(const CheckedPtr &obj, const size_t n);
	friend CheckedPtr operator-(const CheckedPtr &obj, const size_t n);

private:
	int *beg;
	int *end;
	int *curr;
};

CheckedPtr& CheckedPtr::operator++()
{
	if (curr == end)
	{
		std::cout << "error" << std::endl;
	}
	++curr;
	return *this;
}

CheckedPtr CheckedPtr::operator++(int)
{
	CheckedPtr ret(*this);
	++*this;
	return ret;
}

CheckedPtr& CheckedPtr::operator--()
{
	if (curr == beg)
	{
		std::cout << "error" << std::endl;
	}
	--curr;
	return *this;
}

CheckedPtr CheckedPtr::operator--(int)
{
	CheckedPtr ret(*this);
	--*this;
	return ret;
}

int & CheckedPtr::operator[](const size_t index)
{
	if ((curr + index) > end || (curr + index) < end)
	{
		std::cout << "error" << std::endl;
	}
	return *(curr + index);
}

const int& CheckedPtr::operator[](const size_t index) const
{
	if ((curr + index) > end || (curr + index) < end)
	{
		std::cout << "error" << std::endl;
	}
	return *(curr + index);
}

int& CheckedPtr::operator*()
{
	return *curr;
}

const int& CheckedPtr::operator*() const
{
	return *curr;
}

inline bool operator==(const CheckedPtr &obj1, const CheckedPtr &obj2)
{
	return *(obj1.curr) == *(obj2.curr);
}

inline bool operator!=(const CheckedPtr &obj1, const CheckedPtr &obj2)
{
	return !(obj1 == obj2);
}

inline bool operator<(const CheckedPtr &obj1, const CheckedPtr &obj2)
{
	return *(obj1.curr) < *(obj2.curr);
}

CheckedPtr operator+(const CheckedPtr &obj, const size_t n)
{
	if (obj.curr + n > obj.end)
	{
		std::cout << "error" << std::endl;
	}
	CheckedPtr ret(obj);
	ret.curr += n;
	return ret;
}

CheckedPtr operator-(const CheckedPtr &obj, const size_t n)
{
	if (obj.curr - n < obj.beg)
	{
		std::cout << "error" << std::endl;
	}
	CheckedPtr ret(obj);
	ret.curr -= n;
	return ret;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}