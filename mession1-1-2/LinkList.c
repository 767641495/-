#ifndef LinkList_C
#define LinkList_C
#include "LinkList.h"

void OrderInsert(LinkList p, DataElem number)
{
    LinkList temp = p;
    LinkList add = (LinkList)malloc(sizeof(ListNode));
    add->data = number;
    while (temp->next)
    {
        if (number < temp->next->data)
            break;
        temp = temp->next;
    }
    add->next = temp->next;
    temp->next = add;
}

LinkList Merge(LinkList l1, LinkList l2)
{
    LinkList temp = l2;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = l1->next;
    free(l1);
    return l2;
}

void Destroy(LinkList p)
{
    LinkList temp = p;
    while (p != NULL)
    {
        temp = temp->next;
        free(p);
        p = temp;
    }
}

void Show(LinkList p)
//显示链表
{
    LinkList temp = p;
    while (temp->next)
    {
        temp = temp->next;
        printf("%d  ", temp->data);
    }
    puts("\n");
}

#endif