#include <iostream>
using namespace std;

int ArrayPlus1(const int *array)
{
	int add = 0;
	while (*array != 0)
	{
		add += *array++;
	}
	return add;
}

int ArrayPlus2(const int *beg, const int *end)
{
	int add = 0;
	for (;beg != end; ++beg)
	{
		add += *beg;
	}
	return add;
}

int ArrayPlus3(const int *array, size_t size)
{
	int add = 0;
	for (size_t ia = 0; ia != size; ++ia)
	{
		add += array[ia];
	}
	return add;
}

int main(int argc, char const *argv[])
{
	int array[] = {1,1,1,1,1,0};
	int add1 = ArrayPlus1(array);
	int add2 = ArrayPlus2(array, array + 6);
	int add3 = ArrayPlus3(array, 6);
	cout << "add1 = " << add1 << endl;
	cout << "add2 = " << add2 << endl;
	cout << "add3 = " << add3 << endl;
	return 0;
}