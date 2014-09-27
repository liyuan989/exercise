#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string choose;
	do
	{
		string str1;
		string str2;
		cout << "please input two string" << endl;
		cin >> str1 >> str2;
		cout << "the smaller string is " << ((str1 < str2) ? str1 : str2) <<endl;
		cout << "continue? yes or no ?"<< endl;
		cin >> choose;
	}while (choose[0] != 'n');
	return 0;
}