#include <iostream>
#include <list>
#include <string>

int main(int argc, char const *argv[])
{
	std::string array[] = {"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "the", "turtle"};
	std::list<std::string> slist(array, array + 10);
	slist.sort();
	slist.unique();
	for (std::list<std::string>::iterator it = slist.begin(); it != slist.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}