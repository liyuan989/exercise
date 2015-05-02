/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为
输入整数的所有路径。从树的根结点开始往下一直到叶结点
所经过的结点形成一条路径。
 */

#include <vector>
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
    Node* p = new Node;
    p->value = *str;
    p->left = initBinaryTree(++str);
    p->right = initBinaryTree(++str);
    return p;
}

void findAndPrintPath(Node* root, int n, std::vector<char>& path, int current_sum)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->value);
    current_sum += static_cast<int>(root->value - '0');
    if (root->left == NULL && root->right == NULL && current_sum == n)
    {
       for (size_t i = 0; i < path.size(); ++i)
       {
           printf("%c ", path[i]);
       }
       printf("\n");
    }
    findAndPrintPath(root->left, n, path, current_sum);
    findAndPrintPath(root->right, n, path, current_sum);
    path.pop_back();
}

void printPath(Node* root , int n)
{
    if (root == NULL)
    {
        return;
    }
    std::vector<char> path;
    findAndPrintPath(root, n, path, 0);
}

int main(int argc, char* argv[])
{
    const char* str = "954##3##8##";
    Node* root = initBinaryTree(str);
    printPath(root, 17);
    printPath(root, 1);
    printPath(root, -1);
    printPath(root, 18);
    printPath(NULL, 0);
    return 0;
}
