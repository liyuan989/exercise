#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Date;

class CheckoutRecord
{
public:
	friend std::ostream& operator<<(std::ostream &out, const CheckoutRecord &obj);

private:
	double book_id;
	std::string title;
	Date date_borrowed;
	Date date_due;
	std::pair<std::string, std::string> borrower;
	std::vector<std::pair<std::string, std::string>* > wait_list;
};

std::ostream& operator<<(std::ostream &out, const CheckoutRecord &obj)
{
	std::cout << obj.book_id << "\t" << obj.title << "\t" << obj.date_borrowed << "\t"
			  << obj.date_due << "borrower:" << obj.borrower.first << "\t" << borrower.secont
			  << "\t" << "wait_list:" << std::endl;
	for (std::vector<std::pair<std::string, std::string>* >::iterator it = obj.wait_list.begin();
		it != obj.wait_list.end(); ++it)
	{
		std::cout << "\t" << (*it)->first << "\t" << (*it)->second << std::endl;
	}

}

int main(int argc, char const *argv[])
{
	
	return 0;
}