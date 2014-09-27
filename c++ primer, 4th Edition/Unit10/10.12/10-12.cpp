#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> word_count;
	string word;
	while(cin >> word)
	{
		pair<map<string, int>::iterator, bool> val = word_count.insert(make_pair(word, 1));
		if (!val.second)
		{
			++val.first->second;
		}
	}
	cout << word_count["book"] << endl;
}