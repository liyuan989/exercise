#include <iostream>
#include <vector>
#include <tr1/memory>

void exercise1(int *b, int *e)
{
	try
	{
		std::vector<int> v(b, e);
		int *p = new int[v.size()];
		delete p;
	}
	catch (...)
	{
		//delete p;
	}
}

void exercise2(int *b, int *e)
{
	std::vector<int> v(b, e);
	std::tr1::shared_ptr<int> p(new int[v.size()]);
}
