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

class ScrPtr 
{
	friend class ScreenPtr;
	Screen *sp;
	size_t use;
	ScrPtr(Screen *p): sp(p), use(1) { }
	~ScrPtr() { delete sp; }
};


class ScreenPtr 
{
public:
	ScreenPtr(Screen *p): ptr(new ScrPtr(p)) { }
	ScreenPtr(const ScreenPtr &orig): ptr(orig.ptr) { ++ptr->use; }
	~ScreenPtr() { if (--ptr->use == 0) delete ptr; }
	ScreenPtr& operator=(const ScreenPtr&);
	Screen &operator*() { return *ptr->sp; }
	Screen *operator->() { return ptr->sp; }
	const Screen &operator*() const { return *ptr->sp; }
	const Screen *operator->() const { return ptr->sp; }
private:
	ScrPtr *ptr; 
};

ScreenPtr& ScreenPtr::operator=(const ScreenPtr &s)
{
	++s.ptr->use;
	if (--ptr->use == 0)
	{
		delete ptr;
	}
	ptr = s.ptr;
	return *this;
}

class pScreenPtr
{
public:
	pScreenPtr(Screen *p): p_ScreenPtr(new ScreenPtr(p)) {}
	ScreenPtr* operator->()
	{
		return p_ScreenPtr;
	}
	~pScreenPtr() {delete p_ScreenPtr;}
	const ScreenPtr* operator->() const
	{
		return p_ScreenPtr;
	}
	
private:
	ScreenPtr *p_ScreenPtr;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}