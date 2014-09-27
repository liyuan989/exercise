#include <iostream>
#include <string>

class Item_base
{
public:
	Item_base(double book_price = 0.0, std::string book_isbn = ""): price(book_price), isbn(book_isbn) {}
	std::string Book() const {return isbn;}
	virtual double NetPrice(const size_t count = 1) const {return price * count;}
	virtual Item_base* clone() {return new Item_base(*this);}
	virtual void debug(bool choose){if(choose) std::cout << isbn << " " << price << std::endl;}
	
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
	virtual DiscountBook* clone() {return new DiscountBook(*this);}
	virtual void debug(bool choose) {if(choose) {Item_base::debug(choose); std::cout << min_num << " " << discount << std::endl;}}

private:
	size_t min_num;
	double discount;
};

int main(int argc, char const *argv[])
{
	Item_base i;
	//i.debug();
	DiscountBook d;
	//d.debug();
	std::cout << "please select to debug? y/n" << std::endl;
	std::string s;
	std::cin >> s;
	if (s == "y")
	{
		i.debug(true);
		d.debug(true);
	}
}
