#include <iostream>
#include <string>
using namespace std;

void error(string str, int index, int upperbound)
{
	cout << "error1" << endl;
}

void error(string str)
{
	cout << "error2" << endl;
}

void error(string str, char selectval)
{
	cout << "error3" << endl;
}

int main(int argc, char const *argv[])
{
	int index, 
		upperBound;
	char selectVal;
	error("Subscript out of bounds: ", index, upperBound);
	error("Division by zero");
	error("Invalid selection", selectVal);
	return 0;
}