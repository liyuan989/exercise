/*
输入两个递增排序的链表，合并这两个链表并使新链表
中的结点仍然是是按照递增顺序排序的。
 */

#include <stdio.h>
#include <assert.h>

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

Node* merge(Node* head1, Node* head2)
{
    if (head1 == NULL || head2 == NULL || head1->next == NULL || head2->next == NULL)
    {
        return NULL;
    }
    Node* head = head1->next->value < head2->next->value ? head1 : head2;
    Node* p1 = head1->next;
    Node* p2 = head2->next;
    Node* p = head;
    while (p1 && p2)
    {
        if (p1->value < p2->value)
        {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        else
        {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
    }
    if (p1 == NULL)
    {
        p->next = p2;
    }
    else
    {
        p->next = p1;
    }
    if (head == head1)
    {
        delete head2;
    }
    else
    {
        delete head1;
    }
    return head;
}

int main(int argc, char* argv[])
{
    {
        int array1[] = {1, 4, 5, 7, 10};
        int array2[] = {2, 3, 6, 8, 9};
        Node* head1 = initList(array1, 5);
        Node* head2 = initList(array2, 5);
        Node* head3 = merge(head1, head2);
        for (Node* p = head3; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    {
        int array1[] = {1, 2, 3, 4, 5};
        int array2[] = {6, 7, 8, 9, 10};
        Node* head1 = initList(array1, 5);
        Node* head2 = initList(array2, 5);
        Node* head3 = merge(head1, head2);
        for (Node* p = head3; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    {
        int array1[] = {1, 1, 1, 1, 1};
        int array2[] = {1, 1, 1, 1, 1};
        Node* head1 = initList(array1, 5);
        Node* head2 = initList(array2, 5);
        Node* head3 = merge(head1, head2);
        for (Node* p = head3; p->next; p = p->next)
        {
            printf("%d ", p->next->value);
        }
        printf("\n");
    }

    {
        assert(merge(NULL, NULL) == NULL);
    }
    return 0;
}
