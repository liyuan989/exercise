#include <iostream>
#include <string>
#include "linked_queue.h"

int main(int argc, char const *argv[])
{
	linked_queue<int> obj1(8, 9);
	std::cout << obj1.front() << std::endl;
	linked_queue<int> obj2;
	obj2.push(1);
	std::cout << obj2.front() << std::endl;
	obj2.push(2);
	std::cout << obj2.front() << std::endl;
	obj2.pop();
	std::cout << obj2.front() << std::endl;
	return 0;
}