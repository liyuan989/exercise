#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#ifndef NULL
#define NULL 0
#endif

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
class binary_tree
{
private:
	struct Node
	{
		T      data;
		Node*  left_child;
		Node*  right_child;

		friend std::ostream& operator<<(std::ostream& os, const Node& obj)
		{
			os << obj.data;
			return os;
		}
	};

public:
	typedef unsigned int size_type;
	typedef Node*        iterator;

	enum InitParam
	{
		IO,
		STRING
	};

	enum TravaseMethod
	{
		PREORDER,
		INORDER,
		POSTORDER,
		PR_IN_ORDER,
		IN_POST_OREDER  
	};

	enum 
	{
		LEFT = 0,
		RIGHT  
	};

	binary_tree(const InitParam& method, const std::string s = NULL)
		: root(NULL)
	{
		if (method == IO)
		{
			init_io_preorder(root);
		}
		if (method == STRING)
		{
			const char* temp = s.c_str();
			init_string_preorder(root, temp);
		}
	}

	binary_tree(const TravaseMethod& method, const std::string& str1, const std::string& str2)
	{
		if (method == PR_IN_ORDER)
		{
			const char* temp1 = str1.c_str();
			const char* temp2 = str2.c_str();
			init_pre_in_order(root, temp1, temp2, strlen(temp1));
		}
		if (method == IN_POST_OREDER)
		{
			const char* temp1 = str1.c_str();
			const char* temp2 = str2.c_str();
			init_in_post_order(root, temp1, temp2, strlen(temp1));
		}
	}

	binary_tree(const binary_tree& obj)
	{
		copy_subtree(root, obj.root);
	}

	binary_tree& operator=(const binary_tree& obj)
	{
		destroy(root);
		copy_subtree(root, obj.root);
		return *this;
	}

	~binary_tree()
	{
		destroy(root);
	}

	bool empty() const
	{
		return !root;
	}

	size_type depth() const
	{
		return GetDeep(root);
	}

	void print(const TravaseMethod &method) const
	{
		print_out(root, method);
		std::cout << std::endl;
	}

	size_type size() const
	{
		GetSize(root);
	}

	iterator find(const T &val)
	{
		Node* p = NULL;
		find_out(root, p, val);
		return p;
	}

	const iterator find(const T &val) const
	{
		Node* p = NULL;
		find_out(root, p, val);
		return p;
	}

	iterator left_node(iterator obj)
	{
		return obj->left_child;
	}

	const iterator left_node(iterator obj) const
	{
		return obj->left_child;
	}

	iterator right_node(iterator obj)
	{
		return obj->right_child;
	}

	iterator right_node(iterator obj) const
	{
		return obj->right_child;
	}

	void insert(iterator& dest, int which_tree, iterator sub_tree)
	{
		if (!dest)
		{
			std::cout << "error, the target node is a nullptr" << std::endl;		
		}
		if (which_tree == LEFT)
		{
			if (!dest->left_child)
			{
				copy_subtree(dest->left_child, sub_tree);
			}
			else
			{
				std::cout << "error, the target node has a left_child" << std::endl;
			}
		}
		if (which_tree == RIGHT)
		{
			if (!dest->right_child)
			{
				copy_subtree(dest->right_child, sub_tree);
			}
			else
			{
				std::cout << "error, the target node has a right_child" << std::endl;
			}
		}
	}

	void erase(iterator dest, int which_tree)
	{
		if (!dest)
		{
			std::cout << "error, the target node is a nullptr" << std::endl;
		}
		if (which_tree == LEFT)
		{
			if (dest->left_child)
			{
				destroy(dest->left_child);
				dest->left_child = NULL;
			}
			else
			{
				std::cout << "error, the target node don't have left_child" << std::endl;
			}
		}
		if (which_tree == RIGHT)
		{
			if (dest->right_child)
			{
				destroy(dest->right_child);
				dest->right_child = NULL;
			}
			else
			{
				std::cout << "error, the target node don't have right_child" << std::endl;
			}
		}
	}

private:
	void init_io_preorder(Node* &p)
	{
		char ch;
		std::cin >> ch;
		if (std::cin.eof())
		{
			p = NULL;
			return;
		}
		if (ch == '#')
		{
			p = NULL;
		}
		else
		{
			p = new Node;
			init_io_preorder(p->left_child);
			p->data = ch;
			init_io_preorder(p->right_child);
		}
	}

	void init_string_preorder(Node*& p, const char*& s)
	{
		if (*s == '#' || *s == '\0')
		{
			p = NULL;
		}
		else
		{
			p = new Node;
			p->data = *s;
			init_string_preorder(p->left_child, ++s);
			init_string_preorder(p->right_child, ++s);
		}
	}

	void init_pre_in_order(Node*& p, const char* str1, const char* str2, int leng)
	{
		if (!leng)
		{
			return;
		}
		p = new Node;
		p->left_child = NULL;
		p->right_child = NULL;
		p->data = str1[0];

		if (leng == 1)
		{
			return;
		}
		int sub_root = 0;
		for (int i = 0; i != leng; ++i)
		{
			if (str2[i] == str1[0])
			{
				sub_root = i;
				break;
			}
		}
		const char* left_pre = str1 + 1;
		const char* left_in = str2;
		int left_leng = sub_root;
		
		const char* right_pre = str1 + left_leng + 1;
		const char* right_in = str2 + sub_root + 1;
		int right_leng = leng - left_leng - 1;
		init_pre_in_order(p->left_child, left_pre, left_in, left_leng);
		init_pre_in_order(p->right_child, right_pre, right_in, right_leng);
	}

	void init_in_post_order(Node*& p, const char* str1, const char* str2, int leng)
	{
		if (leng == 0)
		{
			return;
		}
		p = new Node;
		p->left_child = NULL;
		p->right_child = NULL;
		p->data = str2[leng - 1];
		if (leng == 1)
		{
			return;
		}
		int sub_root = 0;
		for (int i = 0; i != leng; ++i)
		{
			if (str1[i] == str2[leng - 1])
			{
				sub_root = i;
				break;
			}
		}
		const char* left_in = str1;
		const char* left_post = str2;
		int left_leng = sub_root;

		const char* right_in = str1 + sub_root + 1;
		const char* right_post = str2 + left_leng;
		int right_leng = leng - left_leng - 1;
		init_in_post_order(p->left_child, left_in, left_post, left_leng);
		init_in_post_order(p->right_child, right_in, right_post, right_leng);
	}

	void destroy(Node* p)
	{
		if (!p)
		{
			return;
		}
		else
		{
			destroy(p->left_child);
			destroy(p->right_child);
			delete p;
			p = NULL;
		}
	}

	void print_out(const Node* p, const TravaseMethod &method) const
	{
		if (!p)
		{
			return;
		}
		else
		{
			if (method == PREORDER)
			{
				std::cout << p->data;
				print_out(p->left_child, method);
				print_out(p->right_child, method);
				
			}
			if (method == INORDER)
			{
				print_out(p->left_child, INORDER);
				std::cout << p->data;
				print_out(p->right_child, INORDER);
			}
			if (method == POSTORDER)
			{
				print_out(p->left_child, POSTORDER);
				print_out(p->right_child, POSTORDER);
				std::cout << p->data;
			}
		}
	}	

	size_type GetDeep(const Node* p) const
	{
		size_type deep = 0;
		if (!p)
		{
			return 0;
		}
		size_type left_deep = GetDeep(p->left_child);
		size_type right_deep = GetDeep(p->right_child);
		size_type curr_max = left_deep > right_deep ? left_deep : right_deep;
		if (deep < curr_max)
		{
			deep = curr_max;
		}
		return ++deep;
	}

	size_type GetSize(const Node* p) const
	{
		static size_type n = 0;
		if (!p)
		{
			return n;
		}
		++n;
		GetSize(p->left_child);
		GetSize(p->right_child);
		return n;
	}

	void find_out(Node* p, Node*& dest, const T &val) const
	{
		if (!p)
		{
			return;
		}
		if (dest)
		{
			return;
		}
		if (p->data == val)
		{
			dest = p;
			return;
		}
		find_out(p->left_child, dest, val);
		find_out(p->right_child, dest, val);
	}

	void copy_subtree(Node*& dest, const Node* p)
	{
		if (!p)
		{
			return;
		}
		else
		{
			dest = new Node;
			dest->data = p->data;
			dest->left_child = NULL;
			dest->right_child = NULL;
			copy_subtree(dest->left_child, p->left_child);
			copy_subtree(dest->right_child, p->right_child);
		}
	}

	Node*    root;
};

#endif