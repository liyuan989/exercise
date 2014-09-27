#ifndef __QUERY_H__
#define __QUERY_H__

#include "Handle.h"

class Query_base
{
public:
	friend class Query;
	friend class Handle<Query_base>;

protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base() { }

private:
	virtual std::set<line_no> eval(const TextQuery &obj_TextQuery) const = 0;
	virtual std::ostream& display(std::ostream &os = std::cout) const = 0;
};


class WordQuery : public Query_base
{
	friend class Query;
	friend class Handle<Query_base>;

	WordQuery(const std::string str)
		: query_word(str) {	}

	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const 
	{
		return obj_TextQuery.run_query(query_word);
	}

	virtual std::ostream& display(std::ostream &os = std::cout) const 
	{
		return os << query_word;
	}

	std::string query_word;
};

class Query
{
public:
	friend Query operator&(const Query &obj_Query1, const Query &obj_Query2);
	friend Query operator|(const Query &obj_Query1, const Query &obj_Query2);
	friend Query operator~(const Query &obj_Query);

	Query(const std::string &str)
		: p(new WordQuery(str)) { }

	Query(const Query &obj_Query)
		: p(obj_Query.p) { }

	Query& operator=(const Query &obj_Query)
	{
		p = obj_Query.p;
	}

	std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const 
	{
		return p->eval(obj_TextQuery);
	}

	std::ostream& display(std::ostream &os = std::cout) const 
	{
		return p->display(os);
	}

private:
	Query(Query_base *p_Query_base)
		: p(p_Query_base) { }

	Handle<Query_base> p;

};

std::ostream& operator<<(std::ostream &os, const Query &obj_Query);

class NotQuery : public Query_base
{
private:
	friend Query operator~(const Query &obj_Query);

	NotQuery(const Query &obj_Query)
		: query(obj_Query) { }

	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;

	virtual std::ostream& display(std::ostream &os = std::cout) const 
	{
		return os << "~(" << query << ")";
	}

	const Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &left, const Query &right, const std::string &s)
		: lhs(left), rhs(right), oper(s) {}

	virtual std::ostream& display(std::ostream &os = std::cout) const 
	{
		return os << "(" << lhs << " " << oper << " " << rhs << ")";
	}
	const Query 	  lhs;
	const Query 	  rhs;
	const std::string oper;

};

class AndQuery : public BinaryQuery
{
private:
	AndQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "&") { }

	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;
	friend Query operator&(const Query &obj_Query1, const Query &obj_Query2);
};

class OrQuery : public BinaryQuery
{
private:
	OrQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "|") { }

	virtual std::set<TextQuery::line_no> eval(const TextQuery &obj_TextQuery) const;
	friend Query operator|(const Query &obj_Query1, const Query &obj_Query2);
};

#endif