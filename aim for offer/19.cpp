/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 */

#include <stack>
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

void makeMirrorRecursive(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    makeMirrorRecursive(root->left);
    makeMirrorRecursive(root->right);
}

void makeMirrorLoop(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    std::stack<Node*> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node* p = stack.top();
        stack.pop();
        Node* tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        if (p->right)
        {
            stack.push(p->right);
        }
        if (p->left)
        {
            stack.push(p->left);
        }
    }
}

void print(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c\n", root->value);
    print(root->left);
    print(root->right);
}

int main(int argc, char* argv[])
{
    const char* s = "123##4##56##7##";
    Node* root = initBinaryTree(s);
    makeMirrorRecursive(root);
    makeMirrorLoop(root);
    print(root);
    return 0;
}
