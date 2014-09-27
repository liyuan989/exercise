#include <iostream>
#include <string>

class TreeNode
{
public:
	TreeNode(): left(new TreeNode), right(new TreeNode) {}
	TreeNode(const TreeNode& obj): value(obj.value), count(obj.count) , left(new TreeNode), right(new TreeNode)
	{
		*left = *obj.left;
		*right = *obj.right;
	}
	TreeNode& operator=(const TreeNode &obj)
	{
		value = obj.value;
		count = obj.count;
		*left = *obj.left;
		*right = *obj.right;
		return *this;
	}
	~TreeNode(){delete left, right;}

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree(): root(new TreeNode) {}
	BinStrTree(const BinStrTree& obj): root(new TreeNode) {*root = *obj.root;}
	BinStrTree& operator=(const BinStrTree& obj)
	{
		*root = *obj.root;
		return *this;
	}
	~BinStrTree() {delete root;}

private:
	TreeNode *ro
};

int main(int argc, char const *argv[])
{
	TreeNode t1, t2;
	TreeNode t3 = t1;
	t1 = t2;

	BinStrTree b1, b2;
	BinStrTree b3 = b1;
	b1 = b2;
	return 0;
}