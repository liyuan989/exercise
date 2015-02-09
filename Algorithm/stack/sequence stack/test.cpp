#include <iostream>
#include <string>
#include "SequenceStack.h"

int main(int argc, char const *argv[])
{
	SequenceStack<int> obj;
	obj.push(1);
	std::cout << obj.top() << std::endl;
	obj.push(2);
	std::cout << obj.top() << std::endl;
	obj.pop();
	std::cout << obj.top() << std::endl;
}