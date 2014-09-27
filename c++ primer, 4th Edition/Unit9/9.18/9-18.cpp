#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> ilist(array, array + 10);
	deque<int> ideq_odd;
	deque<int> ideq_even;
	list<int>::iterator iter_ilist = ilist.begin();
	while (iter_ilist != ilist.end())
	{
		if (*iter_ilist & 1)
		{
			ideq_odd.push_back(*iter_ilist);
		}
		else
			ideq_even.push_back(*iter_ilist);
		++iter_ilist;
	}
	deque<int>::iterator it = ideq_odd.begin();
	while (it != ideq_odd.end())
	{
		cout << *it++ << endl;
	}
	it = ideq_even.begin();
	while (it != ideq_even.end())
	{
		cout << *it++ << endl;
	}
	return 0;
}