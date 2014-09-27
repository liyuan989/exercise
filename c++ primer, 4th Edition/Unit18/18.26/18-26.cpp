#include <iostream>
#include <string>

class Screen
{
public:
	typedef std::string::size_type index;
	typedef char (Screen::*Get1)() const;
	typedef char (Screen::*Get2)(index, index) const;
	typedef Screen& (Screen::*Action)();

	Screen(Action ac = &Screen::home)
		: constents(""), cursor(0), height(0), width(0), action(ac)
	{
	}

	void set(Action ac)
	{
		action = ac;
	}

	Screen& home() { std::cout<<111;}
	Screen& end();
	char get() const { }
	char get(index ht, index wd) const { }
	

//private:
	std::string constents;
	index cursor;
	index height;
	index width;
	Action action;
};

int main(int argc, char const *argv[])
{
	Screen obj1;
	Screen obj2;
	obj1.action = &Screen::home;
	(obj2.*(obj1.action))();
	return 0;
}