#include <iostream>
using namespace std;

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val-1) * val;
	}
	return 1;
}

int factorial_iter(int val)
{
	int add = 1;
	for (int n = val; n != 1; --n)
	{
		add *= n;
	}
	return add;
}

int main(int argc, char const *argv[])
{
	cout << factorial(5) << endl;
	cout << factorial_iter(5) <<endl;
	return 0;
}