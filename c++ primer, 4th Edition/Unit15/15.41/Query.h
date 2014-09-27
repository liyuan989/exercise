#ifndef __QUERY_H__
#define __QUERY_H__

class Query;

class Query_base
{
public:
	friend class Query;

protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base() {}

private:
	virtual std::set<line_no> eval(const TextQuery &obj_TextQuery) const = 0;
	virtual std::ostream& display(std::ostream &os = std::cout) const = 0;
};


class WordQuery : public Query_base
{
private:
	friend class Query;
	WordQuery(const std::string str): query_word(str) {}
	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const {return obj_TextQuery.run_query(query_word);}
	virtual std::ostream& display(std::ostream &os = std::cout) const {return os << query_word;}
	std::string query_word;
};

class Query
{
public:
	friend Query operator&(const Query &obj_Query1, const Query &obj_Query2);
	friend Query operator|(const Query &obj_Query1, const Query &obj_Query2);
	friend Query operator~(const Query &obj_Query);

	Query(const std::string &str): p(new WordQuery(str)), count_obj(new size_t(1)) {}
	Query(const Query &obj_Query): p(obj_Query.p), count_obj(obj_Query.count_obj) {++*count_obj;}
	Query& operator=(const Query &obj_Query);
	std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const {return p->eval(obj_TextQuery);}
	std::ostream& display(std::ostream &os = std::cout) const {return p->display(os);}
	~Query() {free_obj();}

private:
	Query(Query_base *p_Query_base): p(p_Query_base), count_obj(new size_t(1)) {}
	Query_base *p;
	size_t *count_obj;
	void free_obj()
	{
		if(--*count_obj == 0)
		{
			delete p;
			delete count_obj;	
		}
	}
};

std::ostream& operator<<(std::ostream &os, const Query &obj_Query);

class NotQuery : public Query_base
{
private:
	friend Query operator~(const Query &obj_Query);
	NotQuery(const Query &obj_Query): query(obj_Query) {}
	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;
	virtual std::ostream& display(std::ostream &os = std::cout) const {return os << "~(" << query << ")";}
	const Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &left, const Query &right, const std::string &s):
		lhs(left), rhs(right), oper(s) {}
	virtual std::ostream& display(std::ostream &os = std::cout) const {return os << "(" << lhs << " " << oper << " " << rhs << ")";}
	const Query lhs;
	const Query rhs;
	const std::string oper;

};

class AndQuery : public BinaryQuery
{
private:
	friend Query operator&(const Query &obj_Query1, const Query &obj_Query2);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {}
	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;
};

class OrQuery : public BinaryQuery
{
private:
	friend Query operator|(const Query &obj_Query1, const Query &obj_Query2);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {}
	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;
};

#endif