#include <vector>
#include <list>
#include <iostream>
using namespace std;

bool ContainerCompare(vector<int> &ivec, list<int> &ilist)
{
	if (ivec.size() != ilist.size())
	{
		return false;
	}
	else
	{
		vector<int>::iterator iter_vec = ivec.begin();
		list<int>::iterator iter_list = ilist.begin();
		while(iter_list != ilist.end())
		{
			if (*iter_list != *iter_vec)
			{
				return false;
			}
			++iter_vec;
			++iter_list;
		}
		return true;
	}
}

int main(int argc, char const *argv[])
{
	int array1[] = {0,1,2,3,4};
	int array2[] = {0,1,2,3,5};
	vector<int> ivec(array1, array1 + 5);
	list<int> ilist1;
	list<int> ilist2(array2, array2 + 5);
	list<int> ilist3(array1, array1 + 5);
	if (ContainerCompare(ivec, ilist1))
	{
		cout << "ivec = ilist1" << endl;
	}
	else
	{
		cout << "ivec != ilist1" << endl;
	}
	if (ContainerCompare(ivec, ilist2))
	{
		cout << "ivec = ilist2" << endl;
	}
	else
	{
		cout << "ivec != ilist2" << endl;
	}
	if (ContainerCompare(ivec, ilist3))
	{
		cout << "ivec = ilist3" << endl;
	}
	else
	{
		cout << "ivec != ilist3" << endl;
	}
	return 0;
}