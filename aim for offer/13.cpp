/*
给定单项链表的头指针和一个结点指针，定义一个函数在O(1)
时间删除该结点。
*/

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

Node* initList(int* array, int size)
{
    if (array == NULL || size == 0)
    {
        return NULL;
    }
    Node* head = new Node;
    Node* p = head;
    for (int i = 0; i < size; ++i)
    {
        p->next = new Node;
        p->next->value = array[i];
        p = p->next;
    }
    return head;
}

void deleteNode(Node* head, Node* pos)
{
    if (head == NULL || pos == NULL || head == pos || head->next == NULL)
    {
        return;
    }
    if (pos->next == NULL)
    {
        while (head->next != pos)
        {
            head = head->next;
        }
        head->next = NULL;
        delete pos;
    }
    else
    {
        pos->value = pos->next->value;
        Node* p = pos->next;
        pos->next = pos->next->next;
        delete p;
    }
}

int main(int argc, char* argv[])
{
    int array[5] = {1, 2, 3, 4, 5};
    Node* head = initList(array, 5);
    deleteNode(head, head->next->next->next);
    for (Node* p = head; p->next; p = p->next)
    {
        printf("%d ", p->next->value);
    }
    printf("\n");

    deleteNode(head, head);
    for (Node* p = head; p->next; p = p->next)
    {
        printf("%d ", p->next->value);
    }
    printf("\n");

    deleteNode(head, head->next->next->next->next);
    for (Node* p = head; p->next; p = p->next)
    {
        printf("%d ", p->next->value);
    }
    printf("\n");

    deleteNode(head, NULL);
    for (Node* p = head; p->next; p = p->next)
    {
        printf("%d ", p->next->value);
    }
    printf("\n");

    deleteNode(NULL, head->next->next);
    for (Node* p = head; p->next; p = p->next)
    {
        printf("%d ", p->next->value);
    }
    printf("\n");
    return 0;
}
