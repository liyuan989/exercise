#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, int> word_count;
	string word;
	while(cin >> word, word != "#")
	{
		if(word == "book")
		{
			++word_count["book"];
		}
	}
	cout << word_count["book"] << endl;
	return 0;
}