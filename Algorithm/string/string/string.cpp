#include <iostream>

#ifndef NULL
#define NULL 0
#endif

typedef unsigned int size_t;

class string
{
public:
	typedef size_t size_type;

	string()
		: str(NULL), length(0)
	{
	}

	string(const char *s)
		: str(NULL), length(0)
	{
		length = strlen(s);
		str = new char[length];
		for (int i = 0; i < length && s[i] != '\0'; ++i)
		{
			str[i] = s[i];
		}
	}

	string(const string &s)
		: str(NULL), length(0)
	{
		length = s.length;
		str = new char[length];
		for (int i = 0; i < length; ++i)
		{
			str[i] = s.str[i];
		}
	}

	~string()
	{
		destroy();
	}

	bool empty() const
	{
		return !length;
	}

	void clear()
	{
		length = 0;
	}

	size_type size() const
	{
		return length;
	}

	bool compare(const string &s) const
	{
		return operator<(*this, s);
	}

	size_t find(const char s) const
	{
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == s)
			{
				return i;
			}
		}
		return 0;
	}

	size_t find(const char *s) const
	{
		int s_length = strlen(s);
		int i = -1;
		int j = -1;
		int next[s_length];
		get_next(s, next, s_length);
		while (i < length && j < s_length)
		{
			if (j == -1 || str[i] == s[j])
			{
				++i;
				++j;
			}
			else
			{
				j = next[j];
			}
		}
		if (j == s_length )
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}

	size_t find(const string &s) const
	{
		int s_length = s.size();
		int i = -1;
		int j = -1;
		int next[s_length];
		get_next(s.str, next, s_length);
		while (i < length && j < s_length)
		{
			if (j == -1 || str[i] == s[j])
			{
				++i;
				++j;
			}
			else
			{
				j = next[j];
			}
		}
		if (j == s_length )
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}

	string substr(size_type pos, size_type len) const
	{
		if (length < pos + len)
		{
		}
		else
		{
			string ret;
			ret.length = len;
			ret.str = new char[len];
			for (int i = 0; i < ret.length; ++i)
			{
				ret.str[i] = str[pos+i];
			}
			return ret;
		}
	}

	void replace(const char *cmp_str, const char *s)
	{
		while(true)
		{
			size_type index = find(cmp_str);
			if (index == -1)
			{
				break;
			}
			else
			{
				erase(index + 1, strlen(cmp_str));
				insert(index + 1, s);
			}
		}
	}

	void insert(size_type pos, const char *s)
	{
		string ret(*this);
		destroy();
		length = ret.length + strlen(s);
		str = new char[length];
		int index = 0;
		for (int i = 0; i < pos - 1; ++i)
		{
			str[index] = ret.str[i];
			++index;
		}
		for (int i = 0; i < strlen(s); ++i)
		{
			str[index] = s[i];
			++index;
		}
		for (int i = pos - 1; i < ret.length; ++i)
		{
			str[index] = ret.str[i];
			++index;
		}
	}

	void erase(size_type pos, size_type len)
	{
		size_type dest = pos + len;
		char *target = &str[dest - 1];
		char *last = &str[length];
		char *temp = &str[pos - 1];
		while (target != last)
		{
			*temp = *target;
			++target;
			++temp;
		}
		length = length - len;
	}

	string& operator=(const string &s)
	{
		if (length == s.length)
		{
			for (int i = 0; i < length; ++i)
			{
				str[i] = s.str[i];
			}
		}
		else
		{
			destroy();
			length = s.length;
			str = new char[length];
			for (int i = 0; i < length; ++i)
			{
				str[i] = s.str[i];
			}
		}
	}

	char& operator[](size_type index)
	{
		return str[index];
	}

	const char& operator[](size_type index) const
	{
		return str[index];
	}

	friend std::ostream& operator<<(std::ostream &os, const string &s)
	{
		for (int i = 0; i < s.length; ++i)
		{
			os << s.str[i];
		}
		return os;
	}

	friend std::istream& operator>>(std::istream &in, string &s)
	{
		in.clear();
		in.sync();
		int count = 0;
		while (in)
		{
			if (!s.length)
			{
				s.length = 1;
				s.str = new char;
				in.get(s.str[0]);
				++count;
			}
			else
			{
				if (count == s.length)
				{
					int cur_size = s.length;
					int target_size = 2 * cur_size;
					char *temp = new char[target_size];
					for (int i = 0; i < cur_size; ++i)
					{
						temp[i] = s.str[i];
					}
					s.destroy();
					s.str = temp;
					s.length = target_size;
				}
				in.get(s.str[count]);
				++count;
			}
		}
		s.length = count - 1;
	}

	friend bool operator==(const string &lhs, const string &rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (int i = 0; i < lhs.size(); ++i)
			{
				if (lhs.str[i] != rhs.str[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator!=(const string &lhs, const string &rhs)
	{
		return !(lhs == rhs);
	}

	friend bool operator<(const string &lhs, const string &rhs)
	{
		size_type lhs_size = lhs.size();
		size_type rhs_size = rhs.size();
		size_type min_length = lhs_size < rhs_size ? lhs_size : rhs_size;
		for (int i = 0; i < min_length; ++i)
		{
			if (lhs.str[i] < rhs.str[i])
			{
				return true;
			}
			if (lhs.str[i] > rhs.str[i])
			{
				return false;
			}
		}
		if (rhs_size != min_length)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator>(const string &lhs, const string &rhs)
	{
		size_type lhs_size = lhs.size();
		size_type rhs_size = rhs.size();
		size_type min_length = lhs_size < rhs_size ? lhs_size : rhs_size;
		for (int i = 0; i < min_length; ++i)
		{
			if (lhs.str[i] < rhs.str[i])
			{
				return false;
			}
			if (lhs.str[i] > rhs.str[i])
			{
				return true;
			}
		}
		if (lhs_size != min_length)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator>=(const string &lhs, const string &rhs)
	{
		return !(lhs < rhs);
	}

	friend bool operator<=(const string &lhs, const string &rhs)
	{
		return !(lhs > rhs);
	}

	friend string operator+(const string &lhs, const string &rhs)
	{
		string s;
		s.length = lhs.size() + rhs.size();
		s.str = new char[s.length];
		int index = 0;
		for (int i = 0; i < lhs.size(); ++i)
		{
			s.str[index] = lhs.str[i];
			++index;
		}
		for (int i = 0; i < rhs.size(); ++i)
		{
			s.str[index] = rhs.str[i];
			++index;
		}
		return s;
	}

private:
	size_type strlen(const char *s) const
	{
		size_type str_size = 0;
		while (*s != '\0')
		{
			++str_size;
			++s;
		}
		return str_size;
	}

	void destroy()
	{
		delete [] str;
		length = 0;
	}

	void get_next(const char *s, int next[], int s_length) const
	{
		int k = -1;
		int j = 0;
		next[0] = -1;
		while (j < s_length )
		{
			if (k == -1 || s[k] == s[j])
			{
				++k;
				++j;
				next[j] = k;
			}
			else
			{
				k = next[k];
			}
		}
	}

	char*  str;
	int    length;
};

int main(int argc, char const *argv[])
{
	//string s1 = "hello!";
	//string s2 = "girl!";
	//string s3 = s1 + s2;
	//std::cout << s3;
	string s1("AABCDABAB");
	//std::cout << s1.find(string("ABAB"));
	s1.replace("AB", "=.=");
	//std::cout << s1 << std::endl;
	
	string s;
	std::cin >> s;
	std::cout << s;
	return 0;
}

