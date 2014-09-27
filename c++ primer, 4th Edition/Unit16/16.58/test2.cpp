#include <iostream>
#include <string>
#include "queue_part_specialization.h"

int main(int argc, char const *argv[])
{
	Queue<const char*> cque;
	cque.push("hello");
	std::cout << cque;
	return 0;
}