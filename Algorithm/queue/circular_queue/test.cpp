#include <iostream>
#include <string>
#include "circular_queue.h"

int main(int argc, char const *argv[])
{
	circular_queue<int, 5> obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	std::cout << obj.front() << std::endl;
	obj.pop();
	std::cout << obj.front() << std::endl;
	obj.push(5);
	obj.pop();
	std::cout << obj.front() << std::endl;
	obj.push(6);
	return 0;
}