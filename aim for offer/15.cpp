/*
输入一个链表，输出该链表中倒数第k个节点。为了符合
大多数人的习惯，本题从1开始计数，即链表的尾节点是
倒数第1个节点。例如一个链表有6个节点，从头节点开始
他们的值依次是1、2、3、4、5、6。这个链表的倒数第3个
节点是值为4的节点
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

Node* findKthToTail(Node* head, int k)
{
    if (head == NULL || k <= 0)
    {
        return NULL;
    }
    Node* first = head->next;
    Node* second = head->next;
    int i = 0;
    for (i = 0; i < k - 1 && first->next; ++i)
    {
        first = first->next;
    }
    if (i != k - 1)
    {
        return NULL;
    }
    while (first->next)
    {
        first = first->next;
        second = second->next;
    }
    return second;
}

int main(int argc, char* argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6};
    Node* head = initList(array, 6);

    assert(findKthToTail(head, 3)->value == 4);
    assert(findKthToTail(head, 7) == NULL);
    assert(findKthToTail(NULL, 3) == NULL);
    assert(findKthToTail(head, 0) == NULL);
    assert(findKthToTail(head, 1)->value == 6);
    assert(findKthToTail(head, 6)->value == 1);

    printf("all test case passed!\n");
    return 0;
}
