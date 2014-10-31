#include <iostream>
#include <string>
#include "SingleList.h"

int main(int argc, char const *argv[])
{
	SingleList<int> obj;
	SingleList<int>::iterator it = obj.begin();
	obj.insert(it, 9);
	std::cout << obj[1];
}