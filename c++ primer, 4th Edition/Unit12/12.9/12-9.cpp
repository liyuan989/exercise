#include <string>
#include <iostream>
typedef int index;
class Screen
{
public:
	typedef std::string::size_type index;
	Screen(index cont, index ht, index wt, std::string ct): cursor(cont), height(ht), width(wt), content(ct) {}
	Screen(): content(), cursor(0), height(0), width(0) {}
	char get() const
	{
		if (content.empty())
		{
			return char();
		}
		else
			return content[cursor];
	}
	char get(index r, index c) const 
	{
		index row = r * width;
		if (content.empty())
		{
			return char();
		}
		else
			return content[cursor + c];
	}

private:
	std::string content;
	index cursor;
	index height;
	index width;

};

int main(int argc, char const *argv[])
{
	Screen myscreen(0,0,0,"hello");
	std::cout << myscreen.get() << std::endl;
	
	return 0;
}