#include <iostream>
#include <vector>
using namespace std;

void ArrayCase()
{
	int array1[] = {0,1,2};
	int array2[5];
	for (int i = 0; i != 3; ++i)
	{
		array2[i] = array1[i];
	}
	cout<<"array2的元素为："<<endl;
	for (int i = 0; i != 3 ; ++i)
	{
		cout<<array2[i]<<"\t";
	}
}

void VectorCase()
{
	int array[3] = {1,2,3};
	vector<int> ivec1(array, array+3);
	vector<int> ivec2(ivec1);
	cout<<"ivec2的元素为："<<endl;
	for (vector<int>::iterator iter = ivec2.begin(); iter != ivec2.end(); ++iter)
	{
		cout<<*iter<<"\t";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	cout<<"ArrayCase"<<endl;
	ArrayCase();
	cout<<endl<<endl<<endl<<"VectorCase"<<endl;
	VectorCase();
	return 0;
}