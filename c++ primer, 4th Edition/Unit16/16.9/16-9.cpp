#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <iterator>

template <class InputIterator, class T>
InputIterator find(InputIterator beg, InputIterator end, const T& val)
{
	while (beg != end)
	{
		if (*beg == val)
		{
			return beg;
		}
		++beg;
	}
	return end;
}

int main(int argc, char const *argv[])
{
	std::vector<int> ivec(8, 9);
	std::list<std::string> slist(8, "hey");
	std::vector<int>::iterator it_int = find(ivec.begin(), ivec.end(), 9);
	std::list<std::string>::iterator it_str = find(slist.begin(), slist.end(), "hey");
	return 0;
}

