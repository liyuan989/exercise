#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> word_count;
	vector<string> word_exclude;
	cout << "please input the word need to be exludeed" << endl;
	string s;
	while(cin >> s)
	{
		word_exclude.push_back(s);
	}
	cin.clear();
	string word;
	cout << "please input the word " << endl;
	while(cin >> word)
	{
		vector<string>::iterator it = word_exclude.begin();
		bool mid = true;
		while(it != word_exclude.end())
		{
			if (word == *it)
			{
				mid == false;
			}
			++it;
		}
		if (mid)
		{
			++word_count[word];
		}
		cin.clear();
	}
	cout << "please input the checking word" << endl;
	cin.clear();
	cin >> word;
	cout << word_count[word];
	return 0;
}