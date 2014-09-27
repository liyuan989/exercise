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
	virtual ~Item_base(){std::cout << "Item_base destructor" << std::endl;test();}

	virtual double NetPrice(const size_t count = 1) const {return price * count;}
	void test() {std::cout << "Item_base test" << std::endl;}
	
protected:
	double price;

private:
	std::string isbn;
};

class DiscountBook : public Item_base
{
public:
	DiscountBook(double book_price = 0.0, std::string book_isbn = "", size_t m = 0, double d = 0.0): 
		Item_base(book_price, book_isbn), min_num(m), discount(d) {std::cout << "DiscountBook constructor" << std::endl;}
	DiscountBook(const DiscountBook &obj): Item_base(obj), min_num(obj.min_num), discount(obj.discount)
	{
		std::cout << "DiscountBook copy constructor" << std::endl;test();
	} 
	DiscountBook& operator=(const DiscountBook &obj)
	{
		Item_base::operator=(obj);
		std::cout << "DiscountBook operator =" << std::endl;test();
		min_num = obj.min_num;
		discount = obj.discount;
	}
	virtual double NetPrice(const size_t count = 2) const
	{
		if (count > min_num)
			return min_num * discount * price + (count - min_num) * price;
		else
			return min_num * discount * price;
	}
	virtual ~DiscountBook(){std::cout << "DiscountBook destructor" << std::endl;test();}
	friend void get(DiscountBook &o){std::cout <<o.price << "\n";}
	void test() {std::cout << "DiscountBook test" << std::endl;}

private:
	size_t min_num;
	double discount;
};

int main(int argc, char const *argv[])
{
	DiscountBook d1;
	Item_base *p = &d1;
}
