#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream &is);
	std::set<line_no> run_query(const std::string &) const;
	std::string text_line(line_no) const;
	void print_result(std::set<line_no>&, TextQuery&);
	int size() const {return line_of_text.size();}
	
private:
	std::map<std::string, std::set<line_no> > word_map;
	std::vector<std::string> line_of_text;
	void store_file(std::ifstream &);
	void build_map();
	void open_file(std::ifstream &, std::string);
};

#endif