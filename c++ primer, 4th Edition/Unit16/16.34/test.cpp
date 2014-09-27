#include <iostream>
#include <string>
#include <vector>
#include "List.h"

int main(int argc, char const *argv[])
{
	int a[] = {0,1,2,3,4};
	std::vector<int> ivec(7, 8);
	List<int> ilist(a, a + 5);
	std::cout << ilist;
	ilist.assign(ivec.begin(), ivec.end());
	std::cout << ilist;
	return 0;
}