#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<pair<string, int> > vec;
	int a;
	string s;
	while(cin >> s >> a, s != "#")
	{
		pair<string, int> data(s, a);
		vec.push_back(data);
	}
	cout << (vec.back()).first << endl;
	cout << (vec.back()).second << endl;
	return 0;
}