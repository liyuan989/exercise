/*
定义一个函数，输入一个链表的头结点，反转该链表并输出
反转后的链表的头结点。
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
    if (array == NULL || size <= 0)
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

void reverseList(Node* head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return;
    }
    Node* prev = head->next;
    Node* middle = head->next->next;
    prev->next = NULL;
    while (middle)
    {
        Node* end = middle->next;
        middle->next = prev;
        prev = middle;
        middle = end;
    }
    head->next = prev;
}

int main(int argc, char* argv[])
{
    {
        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Node* head = initList(array, 10);
        reverseList(NULL);
        reverseList(head);
        for (Node* p = head; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    {
        int array[] = {1, 2};
        Node* head = initList(array, 2);
        reverseList(NULL);
        reverseList(head);
        for (Node* p = head; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    {
        int array[] = {1};
        Node* head = initList(array, 1);
        reverseList(NULL);
        reverseList(head);
        for (Node* p = head; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    return 0;
}
