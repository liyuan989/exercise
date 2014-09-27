#include <iostream>
#include <string>

class Item_base
{
public:
	Item_base(double book_price = 0.0, std::string book_isbn = ""): price(book_price), isbn(book_isbn) {}
	virtual ~Item_base();
	std::string Book() const {return isbn;}
	virtual double NetPrice(const size_t n) const {return price * n;}

protected:
	double price;

private:
	std::string isbn;
};

class Bulk_item : public Item_base
{
public:
	virtual double NetPrice(const size_t n) const 
	{
		if (n >= min_qty)
			return price * n * discount;
		else
			return price * n;
	}

private:
	size_t min_qty;
	double discount;
};