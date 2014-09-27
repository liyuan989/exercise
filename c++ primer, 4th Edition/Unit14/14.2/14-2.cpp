#include <iostream>
#include <string>

class Sales_item
{
public:
	friend std::istream& operator>>(std::istream &in, const Sales_item &obj);
	friend std::ostream& operator<<(std::ostream &out, const Sales_item &obj);
	Sales_item& operator+=(const Sales_item &obk);
};

Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2);

int main(int argc, char const *argv[])
{
	
	return 0;
}