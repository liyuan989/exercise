#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,23,5,7,0,9};
	std::list<int> ilist(array, array + 7);
	int a = 0;
	std::list<int>::reverse_iterator it = std::find(ilist.rbegin(), ilist.rend(), 0);
	//std::find(_InputIterator __first, _InputIterator __last, const _Tp &__val)
	std::cout << *it << std::endl;
	return 0;
}