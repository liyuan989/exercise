#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> ivec(array, array + 10);
	std::fill_n(ivec.begin(), ivec.size(), 0);
	for (int i = 0; i != ivec.size(); ++i)
	{
		std::cout << ivec[i] << std::endl;
	}
	return 0;
}