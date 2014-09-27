#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str("ab2c3d7R4E6");
	string number("0123456789");
	cout << "number pos:" << endl;
	for (string::size_type pos = 0; pos != str.size() ; ++pos)
	{
		string::size_type mid = str.find_first_of("4", pos);
		if (mid != string::npos)
		{
			pos = mid;
			cout << pos << endl;
	
		}
	}
	cout << "alphabet pos:" << endl;
	for (string::size_type pos = 0; pos != str.size() ; ++pos)
	{
		string::size_type mid = str.find_first_not_of(number, pos);
		if (mid != string::npos)
		{
			pos = mid;
			cout << pos << endl;
	
		}
	}
	return 0;
}