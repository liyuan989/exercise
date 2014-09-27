#include <iostream>
#include <string>
#include "Sales_item.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sales_item book1;
	book1.read("0-201-70353-X", 4, 24.99);
	book1.write();
	Sales_item book2;
	book2.read("0-201-70353-Y", 5, 30.55);
	cout << "The average of book1 and book2 is " << book1.ave_two(book2) << endl;

	return 0;
}

void Sales_item::read(std::string str, unsigned a, double b)
{
 	isbn = str;
 	units_sold = a;
 	revenue = b;
}

void Sales_item::write()
{
	cout << "The isbn : " << isbn << endl;
	cout << "The units_sold : "<< units_sold << endl;
	cout << "The revenue : " << revenue << endl;
}

double Sales_item::ave_two(Sales_item &st) const
{
	double average = (units_sold * revenue + st.units_sold * st.revenue) / (units_sold + st.units_sold);
	return average;
}