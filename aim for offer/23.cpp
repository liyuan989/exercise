/*
从上往下打印出二叉树的每个结点，同一层的结点按照
从左到右的顺序打印。
 */

#include <queue>
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

void printBFS(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    std::queue<Node*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        Node* p = queue.front();
        queue.pop();
        if (p->left)
        {
            queue.push(p->left);
        }
        if (p->right)
        {
            queue.push(p->right);
        }
        printf("%c ", p->value);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    const char* s = "123##4##56##7##";
    Node* root = initBinaryTree(s);
    printBFS(root);
    return 0;
}
