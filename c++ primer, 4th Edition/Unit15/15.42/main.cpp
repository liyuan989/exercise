#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <cstdlib>
#include "TextQuery.h"
#include "Query.h"

int main(int argc, char const *argv[])
{
	std::string file;
	if(argc <= 1)
	{
		std::cout << "please input the target file" << std::endl;
		std::cin >> file;
	}
	else if(argc == 2)
	{
		file = argv[1];
	}
	else
	{
		return EXIT_FAILURE;
	}
	std::ifstream input(file.c_str());
	TextQuery check;
	check.read_file(input);
	std::cout << "please input the range of line" << std::endl;
	int beg_line;
	int end_line;
	std::cin >> beg_line >> end_line;

	Query q = Query("I") & Query("never") | Query("is") & ~Query("I");
	std::set<TextQuery::line_no> ret_line = q.eval(check);
	std::cout << "Executing Query for: ";
	q.display();
	check.print_result(ret_line, check, beg_line, end_line);
	system("pause");
	/*
	while(1)
	{
		std::cout << "enter word to check,or q to quit" << std::endl;
		std::string word;
		std::cin >> word;
		if (word == "q")
		{
			break;
		}
		std::set<TextQuery::line_no> target_set = check.run_query(word);
		check.print_result(target_set,check);
	}
	*/
	return 0;
}