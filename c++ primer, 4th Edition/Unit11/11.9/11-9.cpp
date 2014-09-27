#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool IsShorter(const std::string &str1, const std::string str2)
{
	return str1.size() < str2.size();
}

bool IsLongToSix(const std::string &str)
{
	return str.size() >= 4;
}

int main(int argc, char const *argv[])
{
	std::string array[] = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
	std::vector<std::string> svec(array, array + 10);
	std::sort(svec.begin(), svec.end());
	std::stable_sort(svec.begin(), svec.end(), IsShorter);
	std::string::size_type n = std::count_if(svec.begin(), svec.end(), IsLongToSix);
	std::cout << "there have " << n << " words." << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << svec[i] << " ";
	}
	std::cout << std::endl;
}		