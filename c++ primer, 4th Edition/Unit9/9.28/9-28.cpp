#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
	char *a[] = {"hello", "boy", "hey", "girl"};
	list<char*> clist(a, a + 4);
	vector<string> svec(9);
	svec.assign(clist.begin(), clist.end());
	vector<string>::iterator it = svec.begin();
	while(it != svec.end())
	{
		cout<< *it++ << endl;
	}
	return 0;
}