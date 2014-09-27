#include <list>
#include <iostream>
using namespace std;

bool FindInt(list<int>::iterator beg, list<int>::iterator end, int target)
{
	while(beg != end)
	{
		if (*beg == target)
		{
			return true;
		}
		++beg;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int array[] = {0,1,3,5,6,9,8};
	list<int> ilis(array, array + 7);
	cout << FindInt(ilis.begin(), ilis.end(), 9) <<endl;
	return 0;
}