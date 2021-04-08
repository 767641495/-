#ifndef LinkList_C
#define LinkList_C
#include "LinkList.h"

LinkList Create(int iSize) //创建链表,以0~99填充
{
    LinkList p = (LinkList)malloc(sizeof(ListNode));
    LinkList temp = p;
    p->data = 1;
    int i;
    for (i = 2; i <= iSize; i++)
    {
        LinkList a = (LinkList)malloc(sizeof(ListNode));
        a->data = i;
        temp->next = a;
        temp = temp->next;
    }
    temp->next = p;
    return temp;
}

#endif