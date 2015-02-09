#include <iostream>
#include "hashtable.h"

int main(int argc, char const *argv[])
{
	hashtable<char> obj;
	obj.insert('a');
	hashtable<char>::iterator it = obj.find('a');
	std::cout << *it << std::endl;
	obj.erase('a');
	return 0;
}