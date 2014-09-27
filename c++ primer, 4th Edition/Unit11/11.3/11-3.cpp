#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> ivec(array, array + 10);
	int sum = std::accumulate(ivec.begin(), ivec.end(), 0);
	std::cout << sum << std::endl;
	return 0;
}