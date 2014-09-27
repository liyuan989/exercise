#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
	int array[] = {5,1,4,3,2,0};
	std::list<int> ilist(array, array + 6);
	std::vector<int> ivec;
	std::unique_copy(ilist.begin(), ilist.end(), std::back_inserter(ivec));
	for (int i = 0; i < ivec.size(); ++i)
	{
		std::cout << ivec[i] << std::endl;
	}
	return 0;
}