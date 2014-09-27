#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int *p = array, *pend = array + 10; p != pend; ++p)
	{
		*p = 0;
	}
	cout<<"the array is :"<<endl;
	for (int *p = array, *pend = array + 10; p != pend; ++p)
	{
		cout<<*p<<"\t";
	}
	cout<<endl;
	return 0;
}