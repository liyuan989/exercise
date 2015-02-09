#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#ifndef NULL
#define NULL 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#include <iostream>

template<typename T>
class AVLTree
{
private:
	struct node_base
	{
		T 			data;
		node_base*  left_child;
		node_base*  right_child;
		int 		bf;
	};

public:
	AVLTree()
		: root(NULL)
	{
	}

	AVLTree(const AVLTree& obj)
		: root(NULL)
	{
		copy_tree(root, obj.root);
	}

	~AVLTree()
	{
		destroy_tree(root);
	}

	AVLTree& operator=(const AVLTree& obj)
	{
		destroy_tree(root);
		copy_tree(root, obj.root);
	}

	T* insert(const T& key)
	{
		node_base* dest = NULL;
		bool taller = false;
		AVL_search_insert(root, key, dest, taller);
		if (!dest)
		{
			return NULL;
		}
		else
		{
			return &dest->data;
		}
	}

	bool erase(const T& key)
	{
		node_base* dest = NULL;
		bool shorter = false;
		AVL_search_erase(root, key, dest, shorter);
		if (dest)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void print() const
	{
		print_node(root);
		std::cout << std::endl;
	}

private:
	void destroy_tree(node_base*& p)
	{
		if (!p)
		{
			return;
		}
		destroy_tree(p->left_child);
		destroy_tree(p->right_child);
		delete p;
		p = NULL;
	}

	void copy_tree(node_base*& dest, const node_base* p)
	{
		if (!p)
		{
			return;
		}
		dest = new node_base;
		dest->data = p->data;
		dest->bf = p->bf;
		dest->left_child = NULL;
		dest->right_child = NULL;
		copy_tree(dest->left_child, p->left_child);
		copy_tree(dest->right_child, p->right_child);
	}

	void AVL_search_insert(node_base*& p, const T& key, node_base*& dest, bool& taller)
	{
		if (!p)
		{
			p = new node_base;
			p->data = key;
			p->bf = 0;
			p->left_child = NULL;
			p->right_child = NULL;
			dest = p;
			taller = true;
			return;
		}
		if (key == p->data)
		{
			return;
		}
		else if (key < p->data)
		{
			AVL_search_insert(p->left_child, key, dest, taller);
			if (taller)
			{
				switch (p->bf)
				{
					case 1 :
						left_balance(p);
						taller = false;
						break;
					case 0 :
						p->bf = 1;
						taller = true;
						break;
					case -1 :
						p->bf = 0;
						taller = false;
						break;
				}
			}
		}
		else
		{
			AVL_search_insert(p->right_child, key, dest, taller);
			if (taller)
			{
				switch (p->bf)
				{
					case 1 :
						p->bf = 0;
						taller = false;
						break;
					case 0 :
						p->bf = -1;
						taller = true;
						break;
					case -1 :
						right_balance(p);
						taller = false;
						break;
				}
			}
		}
	}

	void right_rotate(node_base*& p)
	{
		node_base* temp = p->left_child;
		p->left_child = temp->right_child;
		temp->right_child = p;
		p = temp;
	}

	void left_rotate(node_base*& p)
	{
		node_base* temp = p->right_child;
		p->right_child = temp->left_child;
		temp->left_child = p;
		p = temp;
	}

	void left_balance(node_base*& p)
	{
		node_base* temp = p->left_child;
		if (temp->bf == 1)
		{
			temp->bf = 0;
			p->bf = 0;
			right_rotate(p);
		}
		if (temp->bf == -1)
		{
			node_base* temp_right = temp->right_child;
			switch (temp_right->bf)
			{
				case 1 :
					temp->bf = 0;
					p->bf = -1;
					break;
				case 0 :
					temp->bf = 0;
					p->bf = 0;
					break;
				case -1 :
					temp->bf = 1;
					p->bf = 0;
					break;
			}
			temp_right->bf = 0;
			left_rotate(temp);
			right_rotate(p);
		}
	}

	void right_balance(node_base*& p)
	{
		node_base* temp = p->right_child;
		if (temp->bf == 1)
		{
			node_base* temp_left = temp->left_child;
			switch (temp_left->bf)
			{
				case 1 :
					p->bf = 0;
					temp->bf = -1;
					break;
				case 0 :
					p->bf = 0;
					temp->bf = 0;
					break;
				case -1 :
					p->bf = 1;
					temp->bf = 0;
					break;
			}
			temp_left->bf = 0;
			right_rotate(temp);
			left_rotate(p);
		}
		if (temp->bf == -1)
		{
			p->bf = 0;
			temp->bf = 0;
			left_rotate(p);
		}
	}

	void print_node(node_base* const& p) const
	{
		if (!p)
		{
			return;
		}
		//std::cout << p->data << "  bf = " << p->bf << std::endl;
		print_node(p->left_child);
		//std::cout << p->data;
		print_node(p->right_child);
		std::cout << p->data;
		//std::cout << p->data << "  bf = " << p->bf << std::endl;
	}

	void AVL_search_erase(node_base*& p, const T& key, node_base*& dest, bool& shorter)
	{
		if (!p)
		{
			return;
		}
		if (key == p->data)
		{
			dest = p;
			if (!p->left_child)
			{
				p = p->right_child;
				shorter = true;
				delete dest;
			}
			else if (!p->right_child)
			{
				p = p->left_child;
				shorter = true;
				delete dest;
			}
			else
			{
				dest = p->left_child;
				while (dest->right_child)
				{
					dest = dest->right_child;
				}
				p->data = dest->data;
				dest = NULL;
				AVL_search_erase(p->left_child, p->data, dest, shorter);
				if (shorter)
				{
					switch (p->bf)
					{
						case 1 :
							p->bf = 0;
							shorter = true;
							break;
						case 0 :
							p->bf = -1;
							shorter = false;
							break;
						case -1 :
							if (!p->right_child->bf)
							{
								shorter = false;
							}
							else
							{
								shorter = true;
							}
							right_balance(p);
							break;
					}
				}
			}
		}
		else if (key < p->data)
		{
			AVL_search_erase(p->left_child, key, dest, shorter);
			if (shorter)
			{
				switch (p->bf)
				{
					case 1 :
						p->bf = 0;
						shorter = true;
						break;
					case 0 :
						p->bf = -1;
						shorter = false;
						break;
					case -1 :
						if (!p->right_child->bf)
						{
							shorter = false;
						}
						else
						{
							shorter = true;
						}
						right_balance(p);
						break;
				}
			}
		}
		else
		{
			AVL_search_erase(p->right_child, key, dest, shorter);
			if (shorter)
			{
				switch (p->bf)
				{
					case 1 :
						if (!p->left_child->bf)
						{
							shorter = false;
						}
						else
						{
							shorter = true;
						}
						left_balance(p);
						break;
					case 0 :
						p->bf = 1;
						shorter = true;
						break;
					case -1 :
						p->bf = 0;
						shorter = true;
						break;
				}
			}
		}
	}

	node_base*  root;
};

#endif