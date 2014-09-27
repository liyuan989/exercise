#include <iostream>
#include "error.h"

namespace MyApp
{
void test()
{
	Bookstore::Sales_item obj1;
	Bookstore::Sales_item obj2("hey");
	Bookstore::Sales_item obj3 = obj1 + obj2;

}
}//namespace MyApp

int main(int argc, char const *argv[])
{
	try
	{
		MyApp::test();
	}
	catch (const Bookstore::isbn_mismatch &e)
	{
		std::cout << "match error" << std::endl;
	}
	return 0;
}