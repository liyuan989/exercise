/*
输入某二叉树的前序遍历和中序遍历结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如，
输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
*/

#include <stdexcept>
#include <stdio.h>

struct Node
{
    Node*  left;
    Node*  right;
    int    value;

    Node()
        : left(NULL), right(NULL), value(0)
    {
    }
};

Node* doConstruct(int* preorder_start, int* preorder_end, int* inorder_start, int* inorder_end)
{
    int root_value = preorder_start[0];
    Node* root = new Node;
    root->value = root_value;

    if (preorder_start == preorder_end)
    {
        if (inorder_start == inorder_end)
        {
            return root;
        }
        else
        {
            throw std::logic_error("Invalid input");
        }
    }

    int* inorder_pos = inorder_start;
    while (inorder_pos <= inorder_end)
    {
        if (*inorder_pos == root_value)
        {
            break;
        }
        ++inorder_pos;
    }
    if (inorder_pos == inorder_end && *inorder_pos != root_value)
    {
        throw std::logic_error("Invalid input");
    }

    int left_length = inorder_pos - inorder_start;
    int* left_preorder_end = preorder_start + left_length;
    if (left_length > 0)
    {
        root->left = doConstruct(preorder_start + 1, left_preorder_end, inorder_start, inorder_pos - 1);
    }
    if (left_length < preorder_end - preorder_start)
    {
        root->right = doConstruct(left_preorder_end + 1, preorder_end, inorder_pos + 1, inorder_end);
    }
    return root;
}

Node* construct(int* preorder, int size_pre, int* inorder, int size_in)
{
    if (preorder == NULL || inorder == NULL || size_pre <= 0 || size_in <= 0)
    {
        return NULL;
    }
    return doConstruct(preorder, preorder + size_pre - 1, inorder, inorder + size_in - 1);
}

void printBinarTreePreorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->value);
    printBinarTreePreorder(root->left);
    printBinarTreePreorder(root->right);
}

int main(int argc, char* argv[])
{
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    Node* root = construct(preorder, sizeof(preorder) / sizeof(int), inorder, sizeof(inorder) / sizeof(int));
    printBinarTreePreorder(root);
    return 0;
}
