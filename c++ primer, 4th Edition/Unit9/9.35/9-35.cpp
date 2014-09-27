#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	string str("WoW");
	string::iterator iter = str.begin();
	while(iter != str.end())
	{
		if (isupper(*iter))
		{
			iter = str.erase(iter);
			--iter;
		}
		++iter;
	}
	cout << str << endl;
	return 0;
}