#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array [10];
	for (int i = 0; i != 10; ++i)
	{
		array[i] = i;
	}
	cout<<"the array is:"<<endl;
	for (int i = 0; i != 10; ++i)
	{
		cout<<"array["<<i<<"] = "<<array[i]<<endl;
	}
	return 0;
}