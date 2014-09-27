#include <iostream>
#include <string>

class Sales_item
{
public:
	Sales_item& operator+=(const Sales_item &obj);
	Sales_item& operator-=(const Sales_item &obj);
	Sales_item& operator=(const Sales_item &obj);
	friend Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2);
	friend Sales_item operator-(const Sales_item &obj1, const Sales_item &obj2);
private:
	std::string isbn;
	int units_sold;
	double revenue;
};

Sales_item& Sales_item::operator+=(const Sales_item &obj)
{
	isbn += obj.isbn;
	units_sold += obj.units_sold;
	revenue += obj.revenue;
}

Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2)
{
	Sales_item mid(obj1);
	mid += obj2;
	return mid;
}

Sales_item& Sales_item::operator-=(const Sales_item &obj)
{
	//isbn -= obj.isbn;
	units_sold -= obj.units_sold;
	revenue -= obj.revenue;
	return *this;
}

Sales_item operator-(const Sales_item obj1, const Sales_item obj2)
{
	Sales_item mid(obj1);
	mid -= obj2;
	return mid;
}

Sales_item& Sales_item::operator=(const Sales_item &obj)
{
	isbn = obj.isbn;
	units_sold = obj.units_sold;
	revenue = obj.revenue;
	return *this;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}