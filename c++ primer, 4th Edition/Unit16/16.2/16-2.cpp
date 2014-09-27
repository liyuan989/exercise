#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

template <typename T>
void WriteStream(std::ostream &os, const T &obj)
{
	os << obj << "\n";
}

int main(int argc, char const *argv[])
{
	std::ofstream out("1.txt");
	std::string s;
	std::ostringstream output(s);

	std::string test1("hello");
	int test2 = 1;
	char test3 = '#';
	double test4 = 9.99;

	WriteStream(std::cout, test1);
	WriteStream(std::cout, test2);
	WriteStream(std::cout, test3);
	WriteStream(std::cout, test4);

	WriteStream(out, test1);
	WriteStream(out, test2);
	WriteStream(out, test3);
	WriteStream(out, test4);

	WriteStream(output, test1);
	std::cout << output.str();
	WriteStream(output, test2);
	std::cout << output.str();
	WriteStream(output, test3);
	std::cout << output.str();
	WriteStream(output, test4);
	std::cout << output.str();
	return 0;
}