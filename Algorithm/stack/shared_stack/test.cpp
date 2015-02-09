#include <iostream>
#include <string>
#include "shared_stack.h"

int main(int argc, char const *argv[])
{
	shared_stack<int, 100> obj;
	obj.push(1, 1);
	std::cout << obj.top(1) << std::endl;
	obj.push(-1, 2);
	std::cout << obj.top(2) << std::endl;
	obj.push(2, 1);
	obj.push(-2, 2);
	std::cout << obj.top(1) << "\n" << obj.top(2) << std::endl;
	obj.pop(1);
	obj.pop(2);
	std::cout << obj.top(1) << "\n" << obj.top(2) << std::endl;
	return 0;
}