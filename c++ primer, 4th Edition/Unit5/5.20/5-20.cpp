#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	cout<<"please input two numbers"<<endl;
	cin>>a>>b;
	if (a > b)
	{
		cout<<"a > b"<<endl;
	}
	else
		cout<<"a < b"<<endl;
	return 0;
}