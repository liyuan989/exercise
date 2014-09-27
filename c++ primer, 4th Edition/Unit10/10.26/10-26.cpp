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
	cout << "please input the author name to check" << endl;
	string author_check;
	cin >> author_check;
	multimap<string, string>::size_type nc = author_book.count(author_check);
	multimap<string, string>::iterator it = author_book.find(author_check);
	cout << author_check << ": ";
	for (int i = 0; i != nc; ++i, ++it)
	{
		cout << it->second << " ";
	}
	cout << endl;
	return 0;
}