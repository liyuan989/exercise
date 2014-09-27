#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
	deque<int> ideq(9,8);
	list<int> ilis(ideq.begin(), ideq.end());
	int n = 0;
	list<int>::iterator it = ilis.begin();
	while(it != ilis.end())
	{
		cout << *it++ << endl;

	}
}