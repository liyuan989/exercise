#include <iostream>
#include <vector>
#include <algorithm>

class GT_val
{
public:
	GT_val(int t = 0): target(t) {}
	bool operator()(int element)
	{
		return element == target;
	}

private:
	int target;
};

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,3,2,1,0};
	std::vector<int> ivec(array, array + 9);
	std::replace_if(ivec.begin(), ivec.end(), GT_val(1), 0);
	for (int i = 0; i < ivec.size(); ++i)
	{
		std::cout << ivec[i] << std::endl;
	}
	return 0;
}