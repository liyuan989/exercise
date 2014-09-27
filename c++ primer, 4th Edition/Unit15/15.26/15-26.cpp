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

class Disc_item : public Item_base
{
public:
	Disc_item(double book_price = 0.0, std::string book_isbn = ""): Item_base(book_price, book_isbn) {}
	virtual ~Disc_item() {}
	virtual double NetPrice(const size_t count = 1) const = 0;
	void get () {NetPrice();}
	/* data */
};

 class derive : public Disc_item
 {
 public:
 	virtual double NetPrice(const size_t count = 1) const
 	{
 		std::cout << 222 << std::endl;
 		return count;
 	}
 };

int main(int argc, char const *argv[])
{
	derive d;
	d.Disc_item::NetPrice();
	return 0;
}