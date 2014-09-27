#include <iostream>
#include <string>

class Item_base
{
public:
	Item_base(double book_price , std::string book_isbn = ""): price(book_price), isbn(book_isbn) {}
	std::string Book() const {return isbn;}
	virtual double NetPrice(const size_t count = 1) const {return price * count;}
	
protected:
	double price;

private:
	std::string isbn;
};

class DiscountBook : public Item_base
{
public:
	virtual double NetPrice(const size_t count = 2) const
	{
		if (count > min_num)
			return min_num * discount * price + (count - min_num) * price;
		else
			return min_num * discount * price;
	}
private:
	size_t min_num;
	double discount;
};

int main(int argc, char const *argv[])
{
}
