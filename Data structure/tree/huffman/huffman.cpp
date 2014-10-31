#include <iostream>
#include <sstream>
#include <map>
#include <string>

struct Node
{
	Node()
		: data('\0'), count(0), parent(-1), left_child(-1), right_child(-1)
	{
	}

	char  	data;
	int     count;
	int		parent;
	int 	left_child;
	int 	right_child;
};

Node h[100];
int root = -1;

int HuffmanInit(const std::string& s)
{
	std::map<char, int> letter_count;
	std::istringstream in(s);
	while(!s.empty() && in)
	{		
		char temp;
		in.get(temp);
		if (in)
		{
			++letter_count[temp];
		}
	}
	int i = 0;
	for (std::map<char, int>::iterator it = letter_count.begin(); it != letter_count.end(); ++it)
	{
		h[i].data = (*it).first;
		h[i].count = (*it).second;
		h[i].parent = -1;
		++i;
	}
	return i;
}

void GetMin(int& min, int& sub_min, int& end_index)
{
	size_t curr_min = -1;
	size_t cur_submin = -1;
	for (int i = 0; i < end_index; ++i)
	{
		if (h[i].parent == -1)
		{
			if (h[i].count < curr_min)
			{
				curr_min = h[i].count;
				min = i;
			}
			else
			{
				if (h[i].count <= cur_submin)
				{
					cur_submin = h[i].count;
					sub_min = i;
				}
			}
		}
	}
}

void CreatTree(int& min, int& sub_min, int& new_index)
{
	h[new_index].count = h[min].count + h[sub_min].count;
	h[new_index].left_child = min;
	h[new_index].right_child = sub_min;
	h[new_index].parent = -1;
	h[min].parent = new_index;
	h[sub_min].parent = new_index;
}

void OutputCode(int n, std::map<char, std::string>& code_table, const std::string& s, std::string& encoded_str)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "num: " << i << " letter : " << h[i].data 
				  << " parent : " << h[i].parent << " count : " << h[i].count << std::endl;
	}
	for (int i = 0; i < n; ++i)
	{
		int curr_index = i;
		while (curr_index != -1)
		{
			if (h[curr_index].parent != -1)
			{
				if (h[h[curr_index].parent].left_child == curr_index)
				{
					code_table[h[i].data].insert(code_table[h[i].data].begin(), '0');
				}
				else
				{
					code_table[h[i].data].insert(code_table[h[i].data].begin(), '1');
				}
			}
			curr_index = h[curr_index].parent;
		}
	}
	for (int i = 0; i < s.size(); ++i)
	{
		encoded_str = encoded_str + code_table[s[i]];
	}
}

std::string HuffmanEncode(int n, const std::string& s, std::map<char, std::string>& code_table)
{
	int array_len = n;
	int new_index = n;
	while (array_len > 1)
	{
		int min = 0;
		int sub_min = 0;
		GetMin(min, sub_min, new_index);
		CreatTree(min, sub_min, new_index);
		--array_len;
		++new_index;
	}
	root = new_index - 1;
	std::string encoded_str;
	OutputCode(n, code_table, s, encoded_str);
	return encoded_str;
}

std::string HuffmanDecode(const std::string& encoded_str)
{
	std::string target;
	for (int curr_index = root, index = 0; index < encoded_str.size();)
	{
		
		if (h[curr_index].left_child == -1 && h[curr_index].right_child == -1)
		{
			target.push_back(h[curr_index].data);
			curr_index = root;
		}
		else
		{
			if (encoded_str[index] == '0')
			{
				curr_index = h[curr_index].left_child;
			}
			if (encoded_str[index] == '1')
			{
				curr_index = h[curr_index].right_child;
			}
			++index;
		}
		if (index == encoded_str.size())
		{
			target.push_back(h[curr_index].data);
		}
	}
	return target;
}

int main(int argc, char const *argv[])
{
	int n = HuffmanInit("aabcdaaa");
	std::map<char, std::string> code_table;
	std::string encoded_str = HuffmanEncode(n, "aabcdaaa",code_table);
	std::cout << "encoded string : " << encoded_str << std::endl;
	std::string target_str = HuffmanDecode(encoded_str);
	std::cout << "decoded string : " << target_str << std::endl;
	return 0;
}