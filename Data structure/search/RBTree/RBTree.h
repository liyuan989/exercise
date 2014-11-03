#ifndef __RBTREE_H__
#define __RBTREE_H__

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
#include <memory.h>

template<typename T>
class RBTree
{
private:
	enum Color
	{
		black,
		red
	};

	struct Node
	{
		T		 data;
		Color    color;
		Node*    parent;
		Node*    left_child;
		Node*    right_child;
	};

public:
	RBTree()
		: root(NULL)
	{
	}

	~RBTree()
	{
		destroy(root);
	}

	void print() const
	{
		std::cout << "=========================== print start =========================" << std::endl;
		do_print(root);
		std::cout << "============================= print end ==========================" << std::endl;
	}

	bool insert(const T& object)
	{
		if (!root)
		{
			root = new Node;
			root->data = object;
			root->color = black;
			root->parent = NULL;
			creat_null_son(root);
			return true;
		}
		else
		{
			Node* destination = NULL;
			Node* root_parent = NULL;
			search_insert(root, root_parent, object, destination);
			if (!destination)
			{
				return false;
			}
			if (destination->parent->color == black)
			{
				insert_case1(destination, object);
				return true;
			}
			else
			{
				if (uncle(destination) && uncle(destination)->color == red)
				{
					insert_case2(destination, object);
				}
				else
				{
					if ( (destination == destination->parent->left_child && 
						destination->parent == grandparent(destination)->left_child) ||
						(destination == destination->parent->right_child &&
						destination->parent == grandparent(destination)->right_child) )
					{
						insert_case3(destination, object);
					}
					else 
					{
						insert_case4(destination, object);
					}
				}
				return true;
			}
		}
	}

	bool erase(const T& object)
	{
		if (!root)
		{
			return false;
		}
		else
		{
			Node* destination = NULL;
			search_erase(root, object, destination);
			if (destination)
			{
				if (destination == root && !root->left_child->left_child && !root->left_child->right_child &&
					!root->right_child->left_child && !root->right_child->right_child)
				{
					destroy(root);
				}
				else if ((destination->color == red) &&
						 (!destination->left_child->left_child && !destination->left_child->right_child) && 
						 (!destination->right_child->left_child && !destination->right_child->right_child))
				{
					if (destination == destination->parent->left_child)
					{
						destination->parent->left_child = destination->left_child;
					}
					else
					{
						destination->parent->right_child = destination->left_child;
					}
					destination->left_child->parent = destination->parent;
					delete destination->right_child;
				}
				else if (destination->color == red)
				{
					Node* position = NULL;
					if (destination->left_child->left_child)
					{
						destination->left_child = destination->parent;
						position = destination->left_child;
						if (destination == destination->parent->left_child)
						{
							destination->parent->left_child = destination->left_child;
						}
						else
						{
							destination->parent->right_child = destination->left_child;
						}
					}
					else
					{
						destination->right_child = destination->parent;
						position = destination->right_child;
						if (destination == destination->parent->left_child)
						{
							destination->parent->left_child = destination->right_child;
						}
						else
						{
							destination->parent->right_child = destination->right_child;
						}
					}
					delete destination;
				}  // equal to "if (destination == black)""
				else
				{
					bool val = erase_black(destination);
					if (!val)
					{
						return false;
					}
				}
				delete destination;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
private:
	void destroy(Node*& p)
	{
		if (!p)
		{
			return;
		}
		destroy(p->left_child);
		destroy(p->right_child);
		delete p;
		p = NULL;
	}

	Node* uncle(Node*& p)
	{
		if (!p)
		{
			std::cout << "p is NULL!" << std::endl;
		}
		if (!p->parent)
		{
			std::cout << "p doesn't have parent!" << std::endl;
		}
		if (!p->parent->parent)
		{
			std::cout << "p doesn't have grandparent" << std::endl;
		}
		if (p->parent == p->parent->parent->left_child)
		{
			return p->parent->parent->right_child;
		}
		else
		{
			return p->parent->parent->left_child;
		}
	}

	Node* brother(Node*& p)
	{
		if (!p)
		{
			std::cout << "p is NULL!" << std::endl;
		}
		if (!p->parent)
		{
			std::cout << "p doesn't have parent!" << std::endl;
		}
		if (p == p->parent->left_child)
		{
			return p->parent->right_child;
		}
		else
		{
			return p->parent->left_child;
		}
	}

	Node* grandparent(Node*& p)
	{
		if (!p)
		{
			std::cout << "p is NULL!" << std::endl;
		}
		if (!p->parent)
		{
			std::cout << "p doesn't have parent!" << std::endl;
		}
		if (!p->parent->parent)
		{
			std::cout << "p doesn't have grandparent" << std::endl;
		}
		return p->parent->parent;
	}

	void left_rotate(Node*& p)
	{
		Node* tmp = p->right_child;
		p->right_child = tmp->left_child;
		if (p->right_child)
		{
			p->right_child->parent = p;
		}
		tmp->left_child = p;
		tmp->parent = p->parent;
		p->parent = tmp;
		p = tmp;
	}

	void right_rotate(Node*& p)
	{
		Node* tmp = p->left_child;
		p->left_child = tmp->right_child;
		if (p->left_child)
		{
			p->left_child->parent = p;
		}
		tmp->right_child = p;
		tmp->parent = p->parent;
		p->parent = tmp;
		p = tmp;
	}

	void creat_null_son(Node*& p)
	{
		p->left_child = new Node;
		memset(&p->left_child->data, 0, sizeof(T));
		p->left_child->color = black;
		p->left_child->left_child = NULL;
		p->left_child->right_child = NULL;
		p->left_child->parent = p;
		p->right_child = new Node;
		memset(&p->right_child->data, 0, sizeof(T));
		p->right_child->color = black;
		p->right_child->left_child = NULL;
		p->right_child->right_child = NULL;
		p->right_child->parent = p;
	}

	void do_print(Node* const& p) const
	{
		if (!p)
		{
			return;
		}
		do_print(p->left_child);
		//do_print(p->right_child);
		if(p->data)
		{
			std::cout << p->data << "  ";
			if (p->color == black)
			{
				std::cout << "black";
			}
			else
			{
				std::cout << "red";
			}
			std::cout << std::endl;
		}
		do_print(p->left_child);
		//do_print(p->right_child);
	}

	void search_insert(Node*& p, Node*& parent, const T& object, Node*& dest)
	{
		if (!p)
		{
			dest = parent;
			return;
		}
		if (object < p->data)
		{
			search_insert(p->left_child, p, object, dest);
		}
		if (object > p->data)
		{
			search_insert(p->right_child, p, object, dest);
		}
	}

	void insert_case1(Node*& destination, const T& object)
	{
		if (!destination->left_child && !destination->right_child)
		{
			creat_null_son(destination);
			destination->data = object;
		}
		destination->color = red;
	}

	void insert_case2(Node*& destination, const T& object)
	{
		if (!destination->left_child && !destination->right_child)
		{
			creat_null_son(destination);
			destination->data = object;
		}
		destination->color = red;
		destination->parent->color = black;
		uncle(destination)->color = black;
		if(destination->parent->parent->parent)
		{
			Node* grandpa = grandparent(destination);
			grandpa->color = red;
			if (grandpa->parent->color == black)
			{
				insert_case1(grandpa, object);
			}
			else
			{
				if (uncle(grandpa)->color == red)
				{
					insert_case2(grandpa, object);
				}
				else 
				{
					if ((grandpa->parent == grandpa->parent->parent->left_child &&
						 grandpa == grandpa->left_child) ||
						(grandpa->parent == grandpa->parent->parent->right_child &&
						 grandpa == grandpa->right_child))
					{
						insert_case3(grandpa, object);
					}
					else
					{
						insert_case4(grandpa, object);
					}
				}
			}
		}
		else
		{
			destination->parent->parent->color = black;
		}
	}

	void insert_case3(Node*& destination, const T& object)
	{
		if (!destination->left_child && !destination->right_child)
		{
			creat_null_son(destination);
			destination->data = object;
		}
		Node* tmp = grandparent(destination);
		if (destination == destination->parent->left_child)
		{
			if (!tmp->parent)
			{
				right_rotate(root);
			}
			else
			{
				if (tmp == tmp->parent->left_child)
				{
					right_rotate(tmp->parent->left_child);
				}
				else
				{
					right_rotate(tmp->parent->right_child);
				}
			}
			tmp->parent->left_child->color = red;
		}
		else
		{
			if (!tmp->parent)
			{
				left_rotate(root);
			}
			else
			{
				if (tmp == tmp->parent->left_child)
				{
					left_rotate(tmp->parent->left_child);
				}
				else
				{
					left_rotate(tmp->parent->right_child);
				}
			}
			tmp->parent->right_child->color = red;
		}
		tmp->color = red;
		tmp->parent->color = black;
	}

	void insert_case4(Node*& destination, const T& object)
	{
		if (!destination->left_child && !destination->right_child)
		{
			creat_null_son(destination);
			destination->data = object;
		}
		Node* tmp = grandparent(destination);
		if (destination == destination->parent->right_child)
		{
			left_rotate(tmp->left_child);
			if (!tmp->parent)
			{
				insert_case3(root->left_child->left_child, object);
			}
			else
			{
				insert_case3(tmp->left_child->left_child, object);
			}	
		}
		else
		{
			right_rotate(tmp->right_child);
			if (!tmp->parent)
			{
				insert_case3(root->right_child->right_child, object);
			}
			else
			{
				insert_case3(tmp->right_child->right_child, object);
			}
		}
	}

	void search_erase(Node*& p, const T& object, Node*& destination)
	{
		if (p)
		{
			if (object == p->data)
			{
				if (p->left_child->left_child &&
					p->left_child->right_child &&
				    p->right_child->left_child &&
				    p->right_child->right_child)
				{
					Node* tmp = p->left_child;
					while (tmp->right_child->right_child)
					{
						tmp = tmp->right_child;
					}
					p->data = tmp->data;
					destination = tmp;
				}
				else
				{
					destination = p;
				}
			}
			else if (object < p->data)
			{
				search_erase(p->left_child, object, destination);
			}
			else
			{
				search_erase(p->right_child, object, destination);
			}
		}
	}

	bool erase_black(Node*& destination)
	{
		if ((destination->left_child && destination->left_child->color == red) || 
			(destination->right_child && destination->right_child->color == red))
		{
			erase_case1(destination);
			return true;
		}
		Node* position = NULL;
		if (destination == destination->parent->left_child)
		{
			if (destination->left_child->left_child)
			{
				destination->parent->left_child = destination->left_child;
				destination->left_child->parent = destination->parent;
				destination->left_child->color = black;
				position = destination->left_child;
			}
			else
			{
				destination->parent->left_child = destination->right_child;
				destination->right_child->parent = destination->parent;
				destination->right_child->color = black;
				position = destination->right_child;
			}
		}
		else
		{
			if (destination->left_child->left_child)
			{
				destination->parent->right_child = destination->left_child;
				destination->left_child->parent = destination->parent;
				destination->left_child->color = black;
				position = destination->left_child;
			}
			else
			{
				destination->parent->right_child = destination->right_child;
				destination->right_child->parent = destination->parent;
				destination->right_child->color =black;
				position = destination->right_child;
			}
		}
		if (brother(position)->color == black)
		{
			Node* brother_node = brother(position);
			if (position->parent->color == red &&
				brother_node->left_child->color == black &&
				brother_node->right_child->color == black)
			{
				erase_case2(position);
			}
			else if ( (position == position->parent->left_child && brother_node->right_child->color == red) ||
					  (position == position->parent->right_child && brother_node->left_child->color == red) )
			{
				erase_case3(position);
			}
			else if ( (position == position->parent->left_child && brother_node->left_child->color == red) ||
					  (position == position->parent->right_child && brother_node->right_child->color == red) )
			{
				erase_case4(position);
			}
			else // parent, brother and brother's every son is a black node
			{
				erase_case6(position);
			}
		}
		else if (brother(position)->color == red)
		{
			erase_case5(position);
		}
		else
		{
			std::cout << "error" << std::endl;
			return false;
		}
		return true;
	}

	void erase_case1(Node*& destination)
	{
		if (destination == root)
		{
			if (destination->left_child->color == red)
			{
				root = destination->left_child;
				destination->left_child->parent = NULL;
				destination->left_child->color = black;
			}
			else
			{
				root = destination->right_child;
				destination->right_child->parent = NULL;
				destination->right_child->color = black;
			}
		}
		else if (destination == destination->parent->left_child)
		{
			if (destination->left_child->color == red)
			{
				destination->parent->left_child = destination->left_child;
				destination->left_child->parent = destination->parent;
				destination->left_child->color = black;
			}
			else
			{
				destination->parent->left_child = destination->right_child;
				destination->right_child->parent = destination->parent;
				destination->right_child->color = black;
			}
		}
		else
		{
			if (destination->left_child->color == red)
			{
				destination->parent->right_child = destination->left_child;
				destination->left_child->parent = destination->parent;
				destination->left_child->color = black;
			}
			else
			{
				destination->parent->right_child = destination->right_child;
				destination->right_child->parent = destination->parent;
				destination->right_child->color = black;
			}
		}
	}

	void erase_case2(Node*& destination)
	{
		destination->parent->color = black;
		brother(destination)->color = red;
	}

	void erase_case3(Node*& destination)
	{
		Node* brother_node = brother(destination); 
		brother_node->color = destination->parent->color;
		destination->parent->color = black;
		if (destination == destination->parent->left_child)
		{
			brother_node->right_child->color = black;
			if (destination->parent == root)
			{
				left_rotate(root);	
			}
			else
			{
				if (destination->parent == destination->parent->parent->left_child)
				{
					left_rotate(destination->parent->parent->left_child);
				}
				else
				{
					left_rotate(destination->parent->parent->right_child);
				}
			}
		}
		else
		{
			brother_node->left_child->color =black;
			if (destination->parent == root)
			{
				right_rotate(root);
			}
			if (destination->parent == destination->parent->parent->left_child)
			{
				right_rotate(destination->parent->parent->left_child);
			}
			else
			{
				right_rotate(destination->parent->parent->right_child);
			}
		}
	}

	void erase_case4(Node*& destination)
	{
		Node* brother_node = brother(destination);
		brother_node->color = red;
		if (destination == destination->parent->left_child)
		{
			brother_node->left_child->color = black;
			right_rotate(destination->parent->right_child);
		}
		else
		{
			brother_node->right_child->color = black;
			left_rotate(destination->parent->left_child);
		}
		erase_case3(destination);
	}

	void erase_case5(Node*& destination)
	{
		Node* brother_node = brother(destination);
		destination->parent->color =red;
		brother_node->color = black;
		bool flag;
		if (destination == destination->parent->left_child)
		{
			flag = true;
			if (destination->parent == destination->parent->parent->left_child)
			{
				left_rotate(destination->parent->parent->left_child);
			}
			else
			{
				left_rotate(destination->parent->parent->right_child);
			}
		}
		else
		{
			flag = false;
			if (destination->parent == destination->parent->parent->left_child)
			{
				right_rotate(destination->parent->parent->left_child);
			}
			else
			{
				right_rotate(destination->parent->parent->right_child);
			}
		}
		brother_node = brother(destination);
		if (brother_node->left_child->color == black && brother_node->right_child->color ==black)
		{
			erase_case2(destination);
		}
		else if ((flag && brother_node->right_child->color == red) || 
				 (!flag && brother_node->left_child->color == red))
		{
			erase_case3(destination);
		}
		else
		{
			erase_case4(destination);
		}
	}

	void erase_case6(RBTree::Node *&destination)
	{
		Node* brother_node = brother(destination);
		brother_node->color = red;
		if (!destination->parent->parent)
		{
			return;
		}
		else
		{
			erase_black(destination);
		}
	}

	Node*	root;
};

#endif