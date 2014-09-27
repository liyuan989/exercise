#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <functional>

int main(int argc, char const *argv[])
{
	int a_int[] = {2000, 9, 1200, 9, 3000};
	for (int *p = a_int; p != a_int + 5; ++p)
	{
		int *pt = std::find_if(p, a_int + 5, std::bind2nd(std::greater<int>(), 1000));
		std::cout << *pt << std::endl;
		if (pt != a_int + 5)
		{
			p = pt;
		}
	}

	std::string s("the quick red fox jumps over the slow red turtle");
	std::istringstream in(s);
	std::vector<std::string> word;
	std::string mid;
	while(in >> mid)
	{
		word.push_back(mid);
	}
	for (std::vector<std::string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		std::vector<std::string>::iterator iter = 
			std::find_if(word.begin(), word.end(), std::bind2nd(std::not_equal_to<std::string>(), "pooh"));
		if (iter == word.end())
		{
			it = iter;
		}
		else
			std::cout << *it << std::endl;
	}

	std::vector<int> ivec(8,2);
	std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind2nd(std::multiplies<int>(), 2));
	for (int i = 0; i < ivec.size(); ++i)
	{
		std::cout << ivec[i] << " ";
	}
	return 0;
}