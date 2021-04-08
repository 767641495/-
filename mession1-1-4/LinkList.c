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
        temp = temp->next;
        if (number < temp->data)
            break;
    }
    add->next = temp->next;
    temp->next = add;
}

void Split(LinkList a,LinkList b)
{
    LinkList temp = a;
    LinkList tempB = b;
    while (temp->next)
    {
        if(temp->next->data % 2)
        {
            tempB->next = temp->next;
            temp->next = temp->next->next;
            tempB = tempB->next;
        }
        else
            temp = temp->next; 
    }
    tempB->next = NULL;
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