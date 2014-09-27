#include <iostream>
#include <string>

class Item_base
{
public:
	Item_base(double book_price = 0.0, std::string book_isbn = ""): 
		price(book_price), isbn(book_isbn) {std::cout<<"Item_base contructor"<< std::endl;}
	std::string Book() const {return isbn;}
	Item_base(const Item_base &obj): price(obj.price), isbn(obj.isbn)
	{std::cout<< "Item_base copy constructor" << std::endl;}
	Item_base& operator=(const Item_base &obj)
	{
		price = obj.price;
		isbn = obj.isbn;
		std::cout << "Item_base operator =" << std::endl;
	}
	virtual ~Item_base(){std::cout << "Item_base destructor" << std::endl;}

	virtual double NetPrice(const size_t count = 1) const {return price * count;}
	virtual std::pair<size_t, double> discount_policy() const {}

protected:
	double price;

private:
	std::string isbn;
};

class Disc_item : public Item_base
{
public:
	Disc_item(double book_price = 0.0, std::string book_isbn = "", size_t q = 0, double d = 0.0): 
		Item_base(book_price, book_isbn), quantity(q), discount(d) {}
	virtual ~Disc_item(){}
	virtual std::pair<size_t, double> discount_policy() const
		{ return std::make_pair(quantity, discount); }

private:
	size_t quantity;
	double discount;
};

int main(int argc, char const *argv[])
{
	Disc_item d;
	Item_base *p = &d;
	p->discount_policy();
}