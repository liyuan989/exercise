#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Date
{
public:
	Date(): year(0), month(0), day(0) {}
	Date(int y, int m, int d): year(y), month(m), day(d) {}
	~Date(){}
	friend std::ostream& operator<<(std::ofstream &output, Date &obj);

private:
	int year;
	int month;
	int day;
};

std::ostream& operator<<(std::ofstream &output, Date &obj)
{
	std::cout << obj.year << "\t" << obj.month << "\t" << obj.day;
}

class CheckoutRecord
{
public:
	friend std::ostream& operator<<(std::ostream &out, const CheckoutRecord &obj);
	friend std::istream& operator>>(std::istream &in, CheckoutRecord &obj);
	CheckoutRecord& operator=(const CheckoutRecord &obj);
	std::pair<std::string, std::string>& operator[](const size_t index) {return *wait_list[index]}
	const std::pair<std::string, std::string>& operator[](const size_t index) const {return *wait_list[index]}

private:
	double book_id;
	std::string title;
	Date date_borrowed;
	Date date_due;
	std::pair<std::string, std::string> borrower;
	std::vector<std::pair<std::string, std::string>* > wait_list;
};

CheckoutRecord& CheckoutRecord::operator=(const CheckoutRecord &obj)
{
	book_id = obj.book_id;
	title = obj.title;
	date_borrowed = obj.date_borrowed;
	date_due = obj.date_due;
	borrower.first = obj.borrower.first;
	borrower.second = obj.borrower.second;
	wait_list.clear();
	for (int i = 0; i != obj.wait_list.size(); ++i)
	{
		wait_list.push_back(std::make_pair(obj.wait_list[i]->first, obj.wait_list[i]->second));
	}
}

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

std::istream& operator>>(std::istream &in, CheckoutRecord &obj)
{
	in >> obj.book_id >> obj.title >> obj.date_borrowed.year >> obj.borrowed.month >> obj.borrowed.day
	   >> obj.date_due.year >> obj.date_due.month >> obj.date_due.day;
	std::string first;
	std::string second;
	in >> first >> second;
	borrower = std::make_pair(first, second);
	while(in)
	{
		std::string vec_first;
		std::string vec_second;
		in >> vec_first >> vec_second;
		std::pair<std::string, std::string>* vpair = &std::make_pair(vec_first, vec_second);
		obj.wait_list.push_back(vpair);
	}
	if (!in)
	{
		obj = CheckoutRecord();
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}