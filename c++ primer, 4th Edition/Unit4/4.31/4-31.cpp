#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	char *str = new char[10]();
	char *p = str;
	char m;
	for (int i = 0 ; i != 10; ++i, ++p)
	{
		cin>>m;
		if (m == '#')
		{
			break;
		}
		*p = m;
	}
	cout<<str<<endl;
	delete [] str;
	str = NULL;
}