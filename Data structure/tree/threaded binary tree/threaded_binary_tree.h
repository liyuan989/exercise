#ifndef __THREADED_BINARY_TREE_H__
#define __THREADED_BINARY_TREE_H__

#ifndef NULL
#define NULL 0
#endif

#include <iostream>

template<typename T>
class threaded_binary_tree
{
private:
	struct Node
	{
		Node()
			: left_child(NULL), right_child(NULL), left_flag(1), right_flag(1)
		{
		}

		T      data;
		Node*  left_child;
		Node*  right_child;
		int    left_flag;
		int    right_flag;

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
		POSTORDER  
	};

	enum 
	{
		LEFT = 0,
		RIGHT  
	};

	enum 
	{
		LINKED,
		THREADED
	};

	threaded_binary_tree(const InitParam method, const std::string s = NULL)
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
		Node* pre_node = NULL;
		get_threaded(root, pre_node);
	}

	threaded_binary_tree(const threaded_binary_tree& obj)
	{
		copy_subtree(root, obj.root);
	}

	threaded_binary_tree& operator=(const threaded_binary_tree& obj)
	{
		destroy(root);
		copy_subtree(root, obj.root);
		return *this;
	}

	~threaded_binary_tree()
	{
		//destroy(root);
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

	void threaded_thravse()
	{
		Node* p = root;
		while (p )
		{
			while(p->left_flag == LINKED)
			{
				p = p->left_child;
			}
			std::cout << p->data;
			while(p->right_flag == THREADED)
			{
				if (!p->right_child)
				{
					return;
				}
				p = p->right_child;
				std::cout << p->data;
			}
			p = p->right_child;
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

	void get_threaded(Node* p, Node*& pre_node)
	{
		if (!p)
		{
			return;
		}
		get_threaded(p->left_child, pre_node);
		if (!p->left_child)
		{
			p->left_flag = THREADED;
			p->left_child = pre_node;
		}
		else
		{
			p->left_flag = LINKED;
		}
		if (pre_node)
		{
			if (!pre_node->right_child)
			{
				pre_node->right_flag = THREADED;
				pre_node->right_child = p;
			}
			else
			{
				pre_node->right_flag = LINKED;
			}
	    }
	    pre_node = p;
		get_threaded(p->right_child, pre_node);
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