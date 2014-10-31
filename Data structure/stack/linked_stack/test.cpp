#include <iostream>
#include <string>
#include "linked_stack.h"

int main(int argc, char const *argv[])
{
	linked_stack<int> obj;
	obj.push(1);
	std::cout << obj.top() << std::endl;
	obj.push(4);
	std::cout << obj.top() << std::endl;
	obj.pop();
	std::cout << obj.top() << std::endl;
	return 0;
}