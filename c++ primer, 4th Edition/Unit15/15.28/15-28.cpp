#include <iostream>
#include <string>
#include <vector>

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
	Bulk_item(double book_price = 0.0, std::string book_isbn = "", size_t c = 0, double d = 0.0): 
		Item_base(book_price, book_isbn), num(c), discount(d) {}
	virtual ~Bulk_item() {}
	virtual  double NetPrice(const size_t count = 1)
	{
		if (count >= num)
			return discount * count *price;
		else
			return count * price;
	}

private:
	size_t num;
	double discount;
};

int main(int argc, char const *argv[])
{
	std::vector<Item_base> item_vec;
	Bulk_item b0;
	Bulk_item b1(1.1);
	Bulk_item b2(1.1, "book");
	Bulk_item b3(1.1, "book", 3);
	Bulk_item b4(1.1, "book", 3, 0.8);
	item_vec.push_back(b0);
	item_vec.push_back(b1);
	item_vec.push_back(b2);
	item_vec.push_back(b3);
	item_vec.push_back(b4);
	size_t count = 0;
	for (std::vector<Item_base>::iterator it = item_vec.begin(); it != item_vec.end(); ++it)
		++count;
	std::cout << "count = " << count << std::endl;

	std::vector<Item_base*> pitem_vec;
	pitem_vec.push_back(&b0);
	pitem_vec.push_back(&b1);
	pitem_vec.push_back(&b2);
	pitem_vec.push_back(&b3);
	pitem_vec.push_back(&b4);
	size_t pcount = 0;
	for (std::vector<Item_base*>::iterator iter = pitem_vec.begin(); iter != pitem_vec.end(); ++iter)
		++pcount;
	std::cout << "pcount = " << pcount << std::endl;

	return 0;
}