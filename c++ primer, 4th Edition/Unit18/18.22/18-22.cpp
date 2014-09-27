#include <iostream>

class Sales_item
{
public:
	Sales_item()
		: isbn(""), units_sold(0), revenue(0.0)
	{
	}

	bool same_isbn(const Sales_item &obj)
	{
		return isbn == obj.isbn;
	}

	double avg_price() const
	{
		return revenue;
	}

	std::string isbn;
	int units_sold;
	double revenue;
};

int main(int argc, char const *argv[])
{
	std::string Sales_item::*p_isbn = &Sales_item::isbn;
	bool (Sales_item::*p_same_isbn) (const Sales_item &obj) = &Sales_item::same_isbn;

	typedef double (Sales_item::*Action) () const;
	Action action = &Sales_item::avg_price;
	Sales_item obj;
	(obj.*action)();
	return 0;
}