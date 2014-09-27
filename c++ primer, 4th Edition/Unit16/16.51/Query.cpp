#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Handle.h"
#include "TextQuery.h"
#include "Query.h"

Query operator&(const Query &obj_Query1, const Query &obj_Query2)
{
	return new AndQuery(obj_Query1, obj_Query2);
}

Query operator|(const Query &obj_Query1, const Query &obj_Query2)
{
	return new OrQuery(obj_Query1, obj_Query2);
}

Query operator~(const Query &obj_Query)
{
	return new NotQuery(obj_Query);
}

inline std::ostream& operator<<(std::ostream &os, const Query &obj_Query)
{
	return obj_Query.display(os);
}

std::set<TextQuery::line_no> NotQuery::eval(const TextQuery &obj_TextQuery) const
{
	std::set<TextQuery::line_no> has_val = query.eval(obj_TextQuery);
	std::set<TextQuery::line_no> ret_line;
	for (int i = 0; i != obj_TextQuery.size(); ++i)
	{
		if (has_val.find(i) == has_val.end())
			ret_line.insert(i);
		return ret_line;
	}

}

std::set<TextQuery::line_no> AndQuery::eval(const TextQuery &obj_TextQuery) const
{
	std::set<TextQuery::line_no> right = rhs.eval(obj_TextQuery);
	std::set<TextQuery::line_no> left = lhs.eval(obj_TextQuery);
	std::set<TextQuery::line_no> ret_line;
	std::set_intersection(right.begin(), 
						  right.end(), 
						  left.begin(), 
						  left.end(), 
						  std::inserter(ret_line, ret_line.begin()));
	return ret_line;
}

std::set<TextQuery::line_no> OrQuery::eval(const TextQuery &obj_TextQuery) const
{
	std::set<TextQuery::line_no> right = rhs.eval(obj_TextQuery);
	std::set<TextQuery::line_no> left = lhs.eval(obj_TextQuery);
	left.insert(right.begin(), right.end());
	return left;
}

