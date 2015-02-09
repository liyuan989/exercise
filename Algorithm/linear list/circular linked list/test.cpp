#include <iostream>
#include <string>
#include "CircularList.h"

int main(int argc, char const *argv[])
{
	CircularList<int> obj;
	CircularList<int>::iterator it = obj.begin();
	obj.insert(it, 9);
	std::cout << obj[1];
}