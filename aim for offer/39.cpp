/*
问题一：

输入一颗二叉树的根结点，求该树的深度。从根结点到叶结点
依次经过的结点（含根、叶结点）形成树的一条路径，最长
路径的长度为树的深度。
*/

#include <assert.h>
#include <stdio.h>

struct Node
{
    Node*  left;
    Node*  right;
    char   value;

    Node()
        : left(NULL), right(NULL), value('\0')
    {
    }
};

Node* initBinaryTree(const char*& str)
{
    if (str == NULL || *str == '#' || *str == '\0')
    {
        return NULL;
    }
    Node* root = new Node;
    root->value = *str;
    root->left = initBinaryTree(++str);
    root->right = initBinaryTree(++str);
    return root;
}

int getBinaryTreeDeep(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_deep = getBinaryTreeDeep(root->left);
    int right_deep = getBinaryTreeDeep(root->right);
    return (left_deep > right_deep ? left_deep : right_deep) + 1;
}

/*
问题二：

输入一颗二叉树的根结点，判断该树是不是平衡二叉树。
如果某个二叉树中任意结点的左子树的深度相差不超过1，
那么它就是一颗平衡二叉树。
*/

bool isBalanceTreeImpl(Node* root, int* deep)
{
    if (root == NULL)
    {
        *deep = 0;
        return true;
    }
    int left_deep;
    int right_deep;
    if (isBalanceTreeImpl(root->left, &left_deep)
        && isBalanceTreeImpl(root->right, &right_deep))
    {
        *deep = (left_deep > right_deep ? left_deep : right_deep ) + 1;
        int diff = left_deep - right_deep;
        if (-1 <= diff && diff <= 1)
        {
            return true;
        }
    }
    return false;
}

bool isBalanceTree(Node* root)
{
    if (root == NULL)
    {
        return false;
    }
    int deep;
    return isBalanceTreeImpl(root, &deep);
}

int main(int argc, char* argv[])
{
    const char* str1 = "124##57###3#6##";
    Node* root1 = initBinaryTree(str1);
    assert(getBinaryTreeDeep(root1) == 4);
    assert(isBalanceTree(root1));

    const char* str2 = "5321###4##76##8##";
    Node* root2 = initBinaryTree(str2);
    assert(getBinaryTreeDeep(root2) == 4);
    assert(isBalanceTree(root2));

    const char* str3 = "123####";
    Node* root3 = initBinaryTree(str3);
    assert(getBinaryTreeDeep(root3) == 3);
    assert(!isBalanceTree(root3));

    printf("all test case passed!\n");
    return 0;
}
