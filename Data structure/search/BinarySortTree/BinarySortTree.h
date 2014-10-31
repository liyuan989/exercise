#ifndef __BINARYSORTTREE_H__
#define __BINARYSORTTREE_H__

#ifndef NULL
#define NULL 0
#endif

template<typename T>
struct node_base
{
	T 			data;
	node_base*  left_child;
	node_base*  right_child;
};

template<typename T>
class BinarySortTree
{
public:
	BinarySortTree()
		: root(NULL)
	{
	}

	BinarySortTree(const BinarySortTree& x)
		: root(NULL)
	{
		copy(root, x.root);
	}
	~BinarySortTree()
	{
		destroy(root);
	}

	T* find(const T& key) const
	{
		node_base<T>* target = NULL;
		bool temp = search(root, NULL, target, key);
		if (temp)
		{
			return &target->data;
		}
		else
		{
			return NULL;
		}
	}

	bool insert(const T& key)
	{
		if (!root)
		{
			root = new node_base<T>;
			root->data = key;
			root->left_child = NULL;
			root->right_child = NULL;
		}
		node_base<T>* dest = NULL;
		bool is_find = search(root, NULL, dest, key);
		if (is_find)
		{
			return false;
		}
		if (key < dest->data)
		{
			node_base<T>* temp = new node_base<T>;
			temp->data = key;
			temp->left_child = NULL;
			temp->right_child = NULL;
			dest->left_child = temp;
			return true;
		}
		else if (key > dest->data)
		{
			node_base<T>* temp = new node_base<T>;
			temp->data = key;
			temp->left_child = NULL;
			temp->right_child = NULL;
			dest->right_child = temp;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool erase(const T& key)
	{
		return search_delete(root, key);
		
	}

private:
	void destroy(node_base<T>* p)
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

	void copy(node_base<T>*& dest, const node_base<T>* p)
	{
		if (!p)
		{
			return;
		}
		dest = new node_base<T>;
		dest->data = p->data;
		dest->left_child = NULL;
		dest->right_child = NULL;
		copy(dest->left_child, p->left_child);
		copy(dest->right_child, p->right_child);
	}

	bool search(node_base<T>* p, node_base<T>* parent, node_base<T>*& target, const T& key) const
	{
		if (!p)
		{
			target = parent;
			return false;
		}
		if (key == p->data)
		{
			target = p;
			return true;
		}
		else if (key < p->data)
		{
			search(p->left_child, p, target, key);
		}
		else
		{
			search(p->right_child, p, target, key);
		}
	}

	bool search_delete(node_base<T>*& p, const T& key)
	{
		if (!p)
		{
			return false;
		}
		if (key == p->data)
		{
			delete_node(p);
			return true;
		}
		else if (key < p->data)
		{
			search_delete(p->left_child, key);
		}
		else
		{
			search_delete(p->right_child, key);
		}
	}

	void delete_node(node_base<T>*& dest)
	{
		if (!dest->left_child && !dest->right_child)
		{
			delete dest;
			dest = NULL;
		}
		else if (dest->left_child && !dest->right_child)
		{
			node_base<T>* temp = dest;
			dest = dest->left_child;
			delete temp;
		}
		else if (!dest->left_child && dest->right_child)
		{
			node_base<T>* temp = dest;
			dest = dest->right_child;
			delete temp;
		}
		else
		{
			node_base<T>* target = dest->left_child;
			node_base<T>* target_parent;
			while (target->right_child)
			{
				target_parent = target;
				target = target->right_child;
			}
			dest->data = target->data;
			if (target == dest->left_child)
			{
				dest->left_child = target->left_child;
			}
			else
			{
				target_parent->right_child = target->left_child;
			}
			delete target;
		}
	}

	node_base<T>*  root;
};

#endif