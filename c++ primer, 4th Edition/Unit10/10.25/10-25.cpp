#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(0));
	string array1[] = {"boy", "gril", "life", "man", "women"};
	string array2[] = {"boy"};
	string mid;
	vector<string> will_read(array1, array1 + 5);
	set<string> have_read(array2, array2 + 1);
	while(1)
	{
		cout << "Do you want read a book ? y/n" << endl;
		cin >> mid;
		if(mid == "n")
			break;
		else
		{
			int n = rand()%4;
			cout << "You can read : " <<will_read[n] << endl;
			pair<set<string>::iterator, bool> val = have_read.insert(will_read[n]);
			cout << "Time fly..." << endl <<"Do you have read " << will_read[n] << "? y/n"  << endl;
			string s1;
			cin >> s1;
			if (s1 == "n")
			{
				have_read.erase(*val.first);
			}
		}
	}
	cout << "6 month later..." << endl;
	cout << "The book you have read : ";
	for (set<string>::iterator it = have_read.begin(); it != have_read.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "The book you haven't read : ";
	for (vector<string>::iterator it = will_read.begin(); it != will_read.end(); ++it)
	{
		if (!have_read.count(*it))
		{
			cout << *it << " ";
		}
	}
	cout << endl;
	return 0;
}