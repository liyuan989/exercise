#include <deque>
#include <iostream>
using namespace std;

deque<int>::iterator FindElement(deque<int>::iterator beg, deque<int>::iterator end, int element)
{
	while (beg != end)
	{
		if (*beg == element)
		{
			return beg;
		}
		++beg;
	}
	cout <<"no this element"<< endl;
	return end;
}

int main(int argc, char const *argv[])
{
	int array[] = {0,2,3,5,7,9,2};
	deque<int> ideq(array, array + 7);
	cout << *FindElement(ideq.begin(), ideq.end(), 9) << endl;
	return 0;
}