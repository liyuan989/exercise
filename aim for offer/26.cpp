/*
请实现函数ComplexListNode* clone(ComplexListNode* head)，
复制一个复杂链表。在复杂链表中，每个结点除了有一个next
指针指向下一个结点外，还有一个sibling指针指向链表中的任意
结点或者NULL。
*/

#include <stdio.h>

struct ComplexListNode
{
    ComplexListNode*  next;
    ComplexListNode*  sibling;
    char              value;

    ComplexListNode()
        :next(NULL), sibling(NULL), value('\0')
    {
    }
};

void insertClonedNode(ComplexListNode* head)
{
    while (head)
    {
        ComplexListNode* cloned = new ComplexListNode;
        cloned->value = head->value;
        cloned->next = head->next;
        head->next = cloned;
        head = cloned->next;
    }
}

void makeSibling(ComplexListNode* head)
{
    ComplexListNode* cloned;
    while (head)
    {
        cloned = head->next;
        if (head->sibling)
        {
            cloned->sibling = head->sibling->next;
        }
        else
        {
            cloned->sibling = NULL;
        }
        head = cloned->next;
    }
}

ComplexListNode* doClone(ComplexListNode* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ComplexListNode* cloned = head->next;
    ComplexListNode* ret = head->next;
    head->next = cloned->next;
    head = head->next;
    while (head)
    {
        cloned->next = head->next;
        cloned = cloned->next;
        head->next = cloned->next;
        head = head->next;
    }
    return ret;
}

ComplexListNode* clone(ComplexListNode* head)
{
    insertClonedNode(head);
    makeSibling(head);
    return doClone(head);
}

ComplexListNode* makeComplexList()
{
    ComplexListNode* head = new ComplexListNode;
    head->value = 'A';
    ComplexListNode* p = head;
    for (int i = 1; i < 5; ++i)
    {
        p->next = new ComplexListNode;
        p->next->value = static_cast<char>('A' + i);
        p = p->next;
    }
    head->sibling = head->next->next;
    head->next->sibling = head->next->next->next->next;
    head->next->next->sibling = NULL;
    head->next->next->next->sibling = head->next;
    head->next->next->next->next->sibling = NULL;
    return head;
}

void printSibling(ComplexListNode* head)
{
    while (head)
    {
        if (head->sibling)
        {
            printf("%c ", head->sibling->value);
        }
        else
        {
            printf("0 ");
        }
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    ComplexListNode* head = makeComplexList();
    ComplexListNode* cloned = clone(head);
    printSibling(cloned);
    return 0;
}
