/*
输入两个链表，找出它们的第一个公共结点。
*/

#include <stdio.h>

struct Node
{
    Node*  next;
    int    value;

    Node()
        : next(NULL), value(0)
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

int getListLength(Node* head)
{
    int length = 0;
    for (Node* p = head->next; p; p = p->next)
    {
        ++length;
    }
    return length;
}

Node* findFirstSharedNode(Node* head1, Node* head2)
{
    if (head1 == NULL || head1->next == NULL || head2 == NULL || head2->next == NULL)
    {
        return NULL;
    }
    int length1 = getListLength(head1);
    int length2 = getListLength(head2);
    int size = length1 > length2 ? length1 - length2 : length2 - length1;
    Node* longer = length1 > length2 ? head1->next : head2->next;
    Node* shorter = length1 > length2 ? head2->next : head1->next;
    for (int i = 0; i < size; ++i)
    {
        longer = longer->next;
    }
    while (longer && shorter && longer->next != shorter->next)
    {
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer->next;
}

int main(int argc, char* argv[])
{
    int array[] = {2, 3, 4, 5, 6};
    Node* head1 = initList(array, 5);
    Node* head2 = new Node;
    Node* p = head2;
    for (int i = 0; i < 2; ++i)
    {
        p->next = new Node;
        p->next->value = i;
        p = p->next;
    }
    head2->next->next->next = head1->next->next;
    printf("%d\n", findFirstSharedNode(head1, head2)->value);
    return 0;
}
