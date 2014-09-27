#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
	multimap<string, string> author_book;
	string author;
	string book;
	cout << "please input author and book name, end of # " << endl;
	while(cin)
	{	cin >> author;
		if (author == "#")
		{
			break;
		}
		cin >> book;
		if (book == "#")
		{
			cout <<"error,please input again, bigen with author" << endl;
			continue;
		}
		author_book.insert(make_pair(author, book));
	}
	multimap<string, string>::iterator it = author_book.begin();
	//author = it->first;
	char letter = (it->first)[0];
	cout << endl << "Author Names Beginning with '" << (it->first)[0] << "':" << endl;
	while(it != author_book.end())
	{
		if ((it->first)[0] != letter)
		{
			cout << endl << "Author Names Beginning with '" << (it->first)[0] << "':" << endl;
			letter = (it->first)[0];
		}
		if (it->first != author)
			{
				author = it->first;
				cout <<author << ", ";
			}
		cout << it->second << ", ";
		++it;
	}
	cout << endl;
}