#include <iostream>
using namespace std;

int Count()
{
	static size_t i = 0;
	int ia = i++;
	if (ia == 0)
	{
		return 0;
	}
	return i;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; ++i)
	{
		cout << Count() << endl;
	}
	return 0;
}