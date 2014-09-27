#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> ivec(array, array + 10);
	std::list<int> ilist(ivec.rbegin() + 3, ivec.rend() - 2);
	for (std::list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}