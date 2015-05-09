/*
问题一：求二叉搜索树中两个结点的最低公共祖先
*/

#include <list>
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
    if (str == NULL || *str == '\0' || *str == '#')
    {
        return NULL;
    }
    Node* root = new Node;
    root->value = *str;
    root->left = initBinaryTree(++str);
    root->right = initBinaryTree(++str);
    return root;
}

Node* lowestCommonAncestorSearchTree(Node* root, Node* a, Node* b)
{
    if (root == NULL || a == NULL || b == NULL)
    {
        return NULL;
    }
    if (root->value > a->value && root->value > b->value)
    {
        return lowestCommonAncestorSearchTree(root->left, a, b);
    }
    else if (root->value < a->value && root->value < b->value)
    {
        return lowestCommonAncestorSearchTree(root->right, a, b);
    }
    else
    {
        return root;
    }
}

/*
问题二：求普通二叉树中两个结点的最低公共祖先，并且每个结点没有指向其父结点的指针。
*/

bool makePathList(Node* root, Node* node, std::list<Node*>& path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root);
    if (root == node)
    {
        return true;
    }
    if (makePathList(root->left, node, path) || makePathList(root->right, node, path))
    {
        return true;
    }
    else
    {
        path.pop_back();
        return false;
    }
}

Node* lowestCommonAncestorBinaryTree(Node* root, Node* a, Node* b)
{
    if (root == NULL || a == NULL || b == NULL)
    {
        return NULL;
    }
    std::list<Node*> path1;
    std::list<Node*> path2;
    if (makePathList(root, a, path1)
        && makePathList(root, b, path2))
    {
        for (std::list<Node*>::iterator it1 = path1.begin(), it2 = path2.begin();
            it1 != path1.end() && it2 != path2.end(); ++it1, ++it2)
        {
            if (*it1 != *it2)
            {
                return *--it1;
            }
        }
        return a;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char* argv[])
{
    {
        const char* str = "5321###4##76##8##";
        Node* root = initBinaryTree(str);
        assert(lowestCommonAncestorSearchTree(root, root->left->left->left, root->left->right)->value == '3');
    }

    {
        const char* str = "5321###4##76##8##";
        Node* root = initBinaryTree(str);
        assert(lowestCommonAncestorSearchTree(NULL, root->left->left->left, root->left->right) == NULL);
        assert(lowestCommonAncestorSearchTree(root, root->left->left->left, NULL) == NULL);
        assert(lowestCommonAncestorSearchTree(root, NULL, root->left->right) == NULL);
        assert(lowestCommonAncestorSearchTree(NULL, NULL, NULL) == NULL);
        Node node;
        assert(lowestCommonAncestorSearchTree(NULL, root->left->left->left, &node) == NULL);
    }

    {
        const char* str = "5321###4##76##8##";
        Node* root = initBinaryTree(str);
        assert(lowestCommonAncestorBinaryTree(root, root->left->left->left, root->left->right)->value == '3');
        assert(lowestCommonAncestorBinaryTree(root, root->left->left->left, root->left->left->left)->value == '1');
    }

    {
        const char* str = "1238###5##36##7##";
        Node* root = initBinaryTree(str);
        assert(lowestCommonAncestorBinaryTree(root, root->left->left->left, root->left->right)->value == '2');
    }

    {
        const char* str = "1238###5##36##7##";
        Node* root = initBinaryTree(str);
        assert(lowestCommonAncestorBinaryTree(NULL, root->left->left->left, root->left->right) == NULL);
        assert(lowestCommonAncestorBinaryTree(root, root->left->left->left, NULL) == NULL);
        assert(lowestCommonAncestorBinaryTree(root, NULL, root->left->right) == NULL);
        assert(lowestCommonAncestorBinaryTree(NULL, NULL, NULL) == NULL);
        Node node;
        assert(lowestCommonAncestorBinaryTree(NULL, root->left->left->left, &node) == NULL);
    }

    printf("all test case passed!\n");
    return 0;
}
