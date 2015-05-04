/*
输入一颗二叉搜索树，将该二叉搜索树换成一个排序的
双向链表。要求不能创建任何新的结点，只能调整树中
结点指针的指向。例如下图中左边的二叉搜索树，则输出
转换之后的排序双向链表。

       4
     /   \
    2     6     =>     1 2 3 4 5 6 7
   / \   / \
  1   3 5   7

*/

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
    Node* head = new Node;
    head->value = *str;
    head->left = initBinaryTree(++str);
    head->right = initBinaryTree(++str);
    return head;
}

void doMakeDoubleList(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    doMakeDoubleList(root->left);
    Node* left_max = root->left;
    while (left_max && left_max->right)
    {
        left_max = left_max->right;
    }
    if (left_max)
    {
        left_max->right = root;
    }
    root->left = left_max;

    doMakeDoubleList(root->right);
    Node* right_min = root->right;
    while (right_min && right_min->left)
    {
        right_min = right_min->left;
    }
    root->right = right_min;
    if (right_min)
    {
        right_min->left = root;
    }
}

// 亦可作为二叉树线索化的方法
Node* makeDoubleList(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    doMakeDoubleList(root);
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

void doMakeDoubleListEfficient(Node* root, Node*& list)
{
    if (root == NULL)
    {
        return;
    }
    doMakeDoubleListEfficient(root->left, list);
    root->left = list;
    if (list)
    {
        list->right = root;
    }
    list = root;
    doMakeDoubleListEfficient(root->right, list);
}

Node* makeDoubleListEfficient(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node* list = NULL;
    doMakeDoubleListEfficient(root, list);
    while (list->left)
    {
        list = list->left;
    }
    return list;
}

int main(int argc, char* argv[])
{
    {
        const char* s = "421##3##65##7##";
        Node* root = initBinaryTree(s);
        Node* list = makeDoubleList(root);
        for (Node* p = list; p; p = p->right)
        {
            printf("%c ", p->value);
        }
        printf("\n");
    }

    {
        const char* s = "421##3##65##7##";
        Node* root = initBinaryTree(s);
        Node* list = makeDoubleListEfficient(root);
        for (Node* p = list; p; p = p->right)
        {
            printf("%c ", p->value);
        }
        printf("\n");
    }
    return 0;
}
