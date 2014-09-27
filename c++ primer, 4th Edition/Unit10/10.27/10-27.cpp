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
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pos = author_book.equal_range(author_check);
	cout << author_check << ": ";
	while(pos.first != pos.second)
	{
		cout  << pos.first->second << " ";
		++pos.first;
	}
	cout << endl;
	return 0;
}