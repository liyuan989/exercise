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
	return str.size() > 6;
}

int main(int argc, char const *argv[])
{
	std::string array[] = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
	std::vector<std::string> svec(array, array + 10);
	std::sort(svec.begin(), svec.end());
	std::stable_sort(svec.begin(), svec.end(), IsShorter);
	int n = 0;
	for (std::vector<std::string>::iterator it = svec.begin(); it != svec.end(); ++it)
	{
		std::vector<std::string>::iterator it_find = std::find_if(it, svec.end(), IsLongToSix);
		if (it_find == svec.end())
		{
			std::cout << "no match word" << std::endl;
			break;
		}
		it = it_find;
		++n;
	}
	if(n > 0)
		std::cout << "there have " << n << " words." << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << svec[i] << " ";
	}
	std::cout << std::endl;
}		