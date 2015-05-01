/*
输入两颗二叉树A和B，判断B是不是A的子结构。
 */

#include <stdio.h>
#include <assert.h>

struct Node
{
    Node*  left;
    Node*  right;
    char    value;

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

bool isSame(Node* root, Node* sub)
{
    if (sub == NULL)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }
    if (root->value == sub->value)
    {
        return isSame(root->left, sub->left) && isSame(root->right, sub->right);
    }
    else
    {
        return false;
    }

}

bool isSubTree(Node* root, Node* sub)
{
    if (root == NULL || sub == NULL)
    {
        return false;
    }
    bool flag = false;
    if (root->value == sub->value)
    {
        flag = isSame(root, sub);
    }
    if (!flag)
    {
        flag = isSubTree(root->left, sub);
    }
    if (!flag)
    {
        flag = isSubTree(root->right, sub);
    }
    return flag;
}

int main(int argc, char* argv[])
{
    const char* s1 = "113##4##56##7##";
    Node* root1 = initBinaryTree(s1);

    {
        const char* s2 = "13##4##";
        Node* root2 = initBinaryTree(s2);
        assert(isSubTree(root1, root2));
    }

    {
        const char* s2 = "11##4##";
        Node* root2 = initBinaryTree(s2);
        assert(!isSubTree(root1, root2));
    }

    {
        const char* s2 = "113##4##56##78###";
        Node* root2 = initBinaryTree(s2);
        assert(!isSubTree(root1, root2));
    }

    {
        assert(!isSubTree(root1, NULL));
        assert(!isSubTree(NULL, root1));
        assert(!isSubTree(NULL, NULL));
    }

    printf("all test case passed!\n");
    return 0;
}
