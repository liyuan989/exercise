#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

bool IsShorter(std::string a, std::string b)
{
	return a.size() < b.size();
}

int main(int argc, char const *argv[])
{
	std::string s("the quick red fox jumps over the slow red turtle");
	std::istringstream in(s);
	std::vector<std::string> word;
	std::string mid;
	while(in)
	{
		in >> mid;
		word.push_back(mid);
	}
	std::sort(word.begin(), word.end());
	std::vector<std::string>::iterator iter_n = std::unique(word.begin(), word.end());
	word.erase(iter_n, word.end());
	std::stable_sort(word.begin(), word.end(), IsShorter);
	
	size_t counts = 0;
	for (std::string::size_type i = 1; i <= 10; ++i)
	{
		for (std::vector<std::string>::iterator it = word.begin(); it != word.end(); ++it)
		{
			std::equal_to<std::string::size_type> obj;
			if (obj((*it).size(), i))
			{
				++counts;
			}
		}
	}
	std::cout << "the counts of word size between 1 and 10 is : " << counts << std::endl;

	return 0;
}