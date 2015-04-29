/*
输入一个链表的头节点，从尾到头反过来打印出每个节点的值
*/

#include <stack>
#include <stdio.h>

struct Node
{
    int    value;
    Node*  next;

    Node()
        : value(0), next(NULL)
    {
    }
};

Node* init(int* array, int size)
{
    if (array == NULL)
    {
        return NULL;
    }
    Node* head = new Node;
    Node* p_node = head;
    for (int i = 0; i < size; ++i)
    {
        p_node->next = new Node;
        p_node->next->value = array[i];
        p_node = p_node->next;
    }
    return head;
}

void printReverseStack(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    std::stack<Node*> stack;
    for (Node* p = head->next; p != NULL; p = p->next)
    {
        stack.push(p);
    }
    while (!stack.empty())
    {
        printf("%d ", stack.top()->value);
        stack.pop();
    }
    printf("\n");
}

void printReverseRecursive(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    if (head->next->next == NULL)
    {
        printf("%d ", head->next->value);
        return;
    }
    printReverseRecursive(head->next);
    printf("%d ", head->next->value);
}

int main(int argc, char* argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    Node* head = init(array, 5);

    printReverseStack(NULL);
    printReverseStack(head);

    printReverseRecursive(NULL);
    printReverseRecursive(head);

    return 0;
}
