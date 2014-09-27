#include <iostream>
#include <string>

class Sales_item
{
public:
	operator std::string() const {return isbn;}
	operator double() const {return revenue;}

private:
	std::string isbn;
	int units_sold;
	double revenue;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}