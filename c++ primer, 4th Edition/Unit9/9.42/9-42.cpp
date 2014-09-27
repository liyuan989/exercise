#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<string> sstk;
	string s;
	while(cin >> s, s != "#")
	{
		sstk.push(s);
	}
	cout << sstk.top() << endl;
	return 0;
}