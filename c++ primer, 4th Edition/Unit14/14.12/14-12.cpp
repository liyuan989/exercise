#include <iostream>
#include <string>

class Sales_item
{
public:
	Sales_item& operator+=(const Sales_item &obj)
	{
		Sales_item mid = *this + obj;
		*this = mid;
		return *this;
	}
	friend Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2);
private:
	std::string isbn;
	int units_sold;
	double revenue;
};

Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2)
{
	Sales_item obj3;
	obj3.isbn = obj1.isbn + obj2.isbn;
	obj3.units_sold = obj1.units_sold + obj2.units_sold;
	obj3.revenue = obj1.revenue + obj2.revenue;
	return obj3;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}