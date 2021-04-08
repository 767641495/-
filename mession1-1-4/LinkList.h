#ifndef LinkList_H
#define LinkList_H

#include "HeadFile.h"

#define ListInitSize 100
#define DataElem int

typedef struct ListNode
{
    DataElem data;
    struct ListNode *next;
} ListNode,*LinkList;

#endif