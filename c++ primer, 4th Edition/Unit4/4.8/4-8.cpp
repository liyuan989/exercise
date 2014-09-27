#include <iostream>
#include <vector>
using namespace std;

void ArrayCompare(int array1[], int size_a,int array2[], int size_b)
{
	if (size_a == size_b)
	{
		for (int i = 0; i != size_a; ++i)
		{
			if (array1[i] != array2[i])
			{
				cout<<"array1 is not equal to array2"<<endl;
				break;
			}
			if (i == size_a-1)
			{
				cout<<"array1 is equal to array2"<<endl;
			}
		}
	}
	else
		cout<<"array1 is not equal to array2"<<endl;
}

void VectorCompare(vector<int> ivec1, vector<int> ivec2)
{
	if (ivec1 == ivec2)
	{
		cout<<"ivec1 is equal to ivec2"<<endl;
	}
	else
		cout<<"ivec1 is not equal to ivec2"<<endl;
}

int main(int argc, char const *argv[])
{
	int a[] = {0,1,2};
	int b[3] = {0,1,2};
	int c[4] = {0,1,2,3};
	int d[3] = {0,1,3};
	ArrayCompare(a, 3, b, 3);
	ArrayCompare(a, 3, c, 4);
	ArrayCompare(a, 3, d, 3);

	vector<int> iv1(8,9);
	vector<int> iv2(8,9);
	vector<int> iv3(9,9);
	vector<int> iv4(8,7);
	VectorCompare(iv1, iv2);
	VectorCompare(iv1, iv3);
	VectorCompare(iv1, iv4);
	return 0;
}