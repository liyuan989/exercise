#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
	int a[] = {0,1,2,3,4,5};
	std::list<int> ilist(a,a + 6);
	std::list<int> ilist2;
	std::replace_copy(ilist.begin(), ilist.end(), std::front_inserter(ilist2), 5, 10);
	//std::replace_copy(ilist.begin(), ilist.end(), std::back_inserter(ilist2), 5, 10);
	//std::replace_copy(ilist.begin(), ilist.end(), std::inserter(ilist2, ilist2.end()), 5, 10);
	for (std::list<int>::iterator it = ilist2.begin(); it != ilist2.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	
	return 0;
}