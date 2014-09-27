#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, string> check_name;
	vector<string> fname_input;
	cout << "please input the family name and name of child: " << endl;
	string f_name;
	string c_name;
	while(cin >> f_name >> c_name)
	{
		check_name.insert(make_pair(f_name, c_name));
		fname_input.push_back(f_name);
	}
	cout << "you have input family name of all:" << endl;
	vector<string>::iterator it = fname_input.begin();
	while(it != fname_input.end())
	{
		cout << *it++ << ",";
	}
	cout << endl;
	int n = 0;
	cout << "the checking result: " << endl;
	while(n != fname_input.size())
	{
		cout << fname_input[n] << ": " << check_name[fname_input[n]] << endl;
		++n;
	}
	return 0;
}