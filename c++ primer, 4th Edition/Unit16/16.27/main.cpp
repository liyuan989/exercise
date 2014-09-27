#include <vector>
#include <iostream>
#include "16-27.h"

int main(int argc, char const *argv[])
{
	int a[] = {4,5,2,6,8,3,65,8,9};
	std::vector<int> ivec(a, a + 9);
	std::cout << std::endl << find_middle(ivec) << "\n";
	size_t n = 0;
	while(n != ivec.size())
	{
		std::cout << ivec[n] << " ";
		++n;
	}
	return 0;
}