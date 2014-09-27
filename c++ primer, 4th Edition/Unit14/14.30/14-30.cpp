#include <string>
#include <iostream>

class Screen
{
public:
	typedef std::string::size_type index;

	Screen(index ct, index ht, index wt, std::string cont):
		content(cont), cursor(ct), height(ht), width(wt) {}
	Screen(): cursor(0), height(0), width(0) {}
	char get() const;
	char get(index r, index c) const;
	Screen& display(std::ostream &os);
	const Screen& display(std::ostream &os) const;
	Screen& set(std::string ct);
	Screen& move(index ht, index wt);

private:
	std::string content;
	index cursor;
	index height;
	index width;
	mutable size_t access_str;

	void do_display(std::ostream &os) const
	{
		os << content;
		++access_str;
	}

};

char Screen::get() const
{
	if (content.empty())
	{
		return char();
	}
	else
		return content[cursor];
}

char Screen::get(index r, index c) const 
{
	index row = r * width;
	if (content.empty())
	{
		return char();
	}
	else
		return content[r + c];
}

Screen& Screen::display(std::ostream &os)
{
	do_display(os);
	return *this;
}

const Screen& Screen::display(std::ostream &os) const
{
	do_display(os);
	return *this;
}

Screen& Screen::set(std::string ct)
{
	content = ct;
	return *this;
}

Screen& Screen::move(index ht, index wt)
{
	height = ht;
	width = wt;
	return *this;
}

class CheckoutPtr
{
public:
	CheckoutPtr(Screen *b, Screen *e): beg(b), end(e), curr(b) {}
	CheckoutPtr& operator++();
	CheckoutPtr operator++(int);
	CheckoutPtr& operator--();
	CheckoutPtr operator--(int);
	Screen& operator*();
	const Screen& operator*() const;
	Screen* operator->();
	const Screen* operator->() const;

private:
	Screen *beg;
	Screen *end;
	Screen *curr;
};

CheckoutPtr& CheckoutPtr::operator++()
{
	if (curr == end)
	{
		std::cout << "error" << std::endl;
	}
	++curr;
	return *this;
}

CheckoutPtr CheckoutPtr::operator++(int)
{
	if (curr == end)
	{
		std::cout << "error" << std::endl;
	}
	CheckoutPtr ret(*this);
	++*this;
	return ret;
}

CheckoutPtr& CheckoutPtr::operator--()
{
	if (curr == beg)
	{
		std::cout << "error" << std::endl;
	}
	--curr;
	return *this;
}

CheckoutPtr CheckoutPtr::operator--(int)
{
	if (curr == beg)
	{
		std::cout << "error" << std::endl;
	}
	CheckoutPtr ret(*this);
	--*this;
	return ret;
}

Screen& CheckoutPtr::operator*()
{
	return *curr;
}

const Screen& CheckoutPtr::operator*() const
{
	return *curr;
}

Screen* CheckoutPtr::operator->()
{
	return curr;
}

const Screen* CheckoutPtr::operator->() const
{
	return curr;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}