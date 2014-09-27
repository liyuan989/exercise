#include <iostream>
#include <vector>
#include "queue.h"

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4};
	std::vector<int> ivec(8,9);
	queue<int> ique(array, array + 5);
	std::cout << ique;
	ique.assign(ivec.begin(), ivec.end());
	std::cout << ique;
	std::cin >> ique;
	std::cout << ique;

	return 0;
}