#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdexcept>

namespace Bookstore
{
class out_of_stock : public std::runtime_error
{
public:
	explicit out_of_stock(const std::string &s)
		: std::runtime_error(s) { }
};

class isbn_mismatch : public std::logic_error
{
public:
	explicit isbn_mismatch(const std::string &s)
		: std::logic_error(s) { }

	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs)
		: std::logic_error(s), left(lhs), right(rhs) { }

	virtual ~isbn_mismatch() throw() { }

	const std::string left;
	const std::string right;
};

class Sales_item
{
public:
	Sales_item()
		: isbn(""), units_sold(0), revenue(0.0) { }

	Sales_item(const std::string &s)
		: isbn(s), units_sold(0), revenue(0.0) { }

	Sales_item& operator+=(const Sales_item &obj)
	{
		Sales_item mid = *this + obj;
		*this = mid;
		return *this;
	}

	bool same_isbn(const Sales_item &obj) const
	{
		if (isbn == obj.isbn &&
			units_sold == obj.units_sold &&
			revenue == obj.revenue)
		{
			return true;
		}
		else
			return false;
	}

	friend Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2);
private:
	std::string isbn;
	int units_sold;
	double revenue;
};

Sales_item operator+(const Sales_item &obj1, const Sales_item &obj2)
{
	if (!obj1.same_isbn(obj2))
	{
		throw isbn_mismatch("not match");
	}
	Sales_item obj3;
	obj3.isbn = obj1.isbn + obj2.isbn;
	obj3.units_sold = obj1.units_sold + obj2.units_sold;
	obj3.revenue = obj1.revenue + obj2.revenue;
	return obj3;
}

}//namesapce Bookstore

#endif