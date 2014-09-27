#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	string str("(boy + girl) + (man + woman)");
	stack<char> sstk;
	for (string::size_type pos = 0; pos != str.size(); ++pos)
	{
		string::size_type mid = str.find('(', pos);
		if (mid != string::npos)
		{
			pos = mid;
			int n = 0;
			while(str[pos] != ')' )
			{
				sstk.push(str[pos]);
				++pos;
				++n;
			}
			cout << "This top element of stack at this time is: "<< sstk.top() << endl;
			char value = sstk.top();
			while(n != 0)
				{
					sstk.pop();
					--n;
				}
			sstk.push('K');
			}
		}
	cout << "The counts of handled expression between ( and ) is " << sstk.size() << endl;
	return 0;
}