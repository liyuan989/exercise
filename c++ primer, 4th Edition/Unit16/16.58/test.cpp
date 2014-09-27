#include <iostream>
#include <string>
#include "queue_specialization.h"

int main(int argc, char const *argv[])
{
	Queue<const char*> sque;
	sque.push("hello");
	std::cout << sque;
	return 0;
}