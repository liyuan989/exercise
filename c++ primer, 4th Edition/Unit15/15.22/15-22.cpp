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
	void test() {std::cout << "Item_base test" << std::endl;}
	
protected:
	double price;

private:
	std::string isbn;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(double book_price = 0.0, std::string book_isbn = "", size_t m = 0, double d = 0.0):
		Item_base(book_price, book_isbn), min_qty(m), discount(d) {}
	virtual ~Bulk_item(){}
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
	Bulk_item b;
	b.test();
}
