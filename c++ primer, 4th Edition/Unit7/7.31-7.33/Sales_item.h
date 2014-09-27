#ifndef __SALES_ITEM_H__
#define __SALES_ITEM_H__
#include <string>

class Sales_item
{
public:
	Sales_item(): units_sold(0), revenue(0.0) { }
	void read(std::string str, unsigned a, double b);
	void write();
	double ave_two(Sales_item &st) const;
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

#endif