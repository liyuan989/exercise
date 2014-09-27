#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
#define Data pair<string, int>
int main(int argc, char const *argv[])
{
	vector<Data> vec;
	int a;
	string s;
	/* 第一种方法
	while(cin >> s >> a, s != "#")
	{
		pair<string, int> data(s, a);
		vec.push_back(data);
	}
	cout << vec.back().first << endl;
	cout << vec.back().second << endl;
	*/
	/*第二种方法
	while(cin >> s >> a, s != "#")
	{
		Data data;
		data.first = s;
		data.second = a;
		vec.push_back(data);
	}
	cout << vec.back().first << endl;
	cout << vec.back().second << endl;
	*/
	//第三种方法
	while(cin >> s >> a, s != "#")
	{
		Data data = make_pair(s, a);
		vec.push_back(data);
	}
	cout << vec.back().first << endl;
	cout << vec.back().second << endl;

	return 0;
}