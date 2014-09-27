#ifndef __TEXTCHECK_H__
#define __TEXTCHECK_H__

class textcheck
{
public:
	typedef std::string::size_type line_n;
	void load_file(std::ifstream &input);
	void run_file();
	std::vector<line_n> check_out(const std::string &) const;
	void print_result(std::vector<line_n> &, std::string, textcheck &) const;
	
private:
	std::vector<std::string> word_line;
	std::map<std::string, std::vector<line_n> > word_map;
	std::vector<std::string> word_line hey_boy;
};

#endif