#include <iostream>
#include <vector>
#include <list>
using namespace std;

void EraselistOdd(list<int> &ilist)
{
	list<int>::iterator it = ilist.begin();
	while(it != ilist.end())
	{
		if (*it & 1)
		{
			it = ilist.erase(it);
			--it;
		}
		++it;
	}
}

void EraseVectorEven(vector<int> &ivec)
{
	vector<int>::iterator it = ivec.begin();
	while(it != ivec.end())
	{
		if (!(*it & 1))
		{
			it = ivec.erase(it);
			--it;
		}
		++it;
	}
}

int main(int argc, char const *argv[])
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> ivec(ia, ia + 11);
	list<int> ilist(ia, ia + 11);
	EraselistOdd(ilist);
	EraseVectorEven(ivec);
	cout << "ivec: " << "\t";
	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl << "ilist: " << "\t";
	for (list<int>::iterator it = ilist.begin(); it != ilist.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	return 0;
}