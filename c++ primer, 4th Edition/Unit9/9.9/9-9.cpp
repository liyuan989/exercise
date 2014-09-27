#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> ilis(array, array + 10);
	list<int>::iterator iter = ilis.end();
	while (iter-- != ilis.begin())
	{
		cout << *iter << endl;
	}
	return 0;
}