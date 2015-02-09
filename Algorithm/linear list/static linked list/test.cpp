#include <iostream>
#include <string>
#include "StaticList.h"

int main(int argc, char const *argv[])
{
	StaticList<int, 100> obj(1,9);
	obj.insert(1, 10);
	std::cout << obj[2] << "\n";
	obj.insert(2, 11);
	obj.erase(1);
	std::cout << obj[2];
	return 0;
}