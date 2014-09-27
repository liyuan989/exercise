#include <iostream>
#include <string>

class book
{
public:
	book(std::ifstream &input): count(0), name(NULL), in(input) {}
	~book() {}

private:
	const std::string isba;
	int count;
	double *name;
	std::ifstream &in;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}