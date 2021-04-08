#include "LinkList.c"
#include "Color.h"
#include "Read.h"
const int inf = ~0u >> 2;
int main()
{
    system("cls");
    printf(LIGHT_BLUE "请输入您要输入的整数个数[1,100000]：" NONE);
    int n = Read(1, 100000);
    int i = 0;
    LinkList listA = (LinkList)malloc(sizeof(ListNode));
    listA->next = NULL;
    LinkList listB = (LinkList)malloc(sizeof(ListNode));
    listB->next = NULL;
    while (i < n)
    {
        printf(LIGHT_PURPLE "请输入您要插入链表中的第%d个整数：" NONE, ++i);
        int number = Read(-inf, inf);
        OrderInsert(listA, number);
        printf(LIGHT_CYAN "链表为：\n" NONE);
        Show(listA);
        system("pause");
        system("cls");
    }
    Split(listA, listB);
    printf(GREEN "链表分离成功！！！\n\n" NONE);
    printf(LIGHT_CYAN "您的原链表为：\n" NONE);
    Show(listA);
    printf(LIGHT_GREEN "您的新链表为：\n" NONE);
    Show(listB);
    Destroy(listA);
    Destroy(listB);
    printf(RED "程序运行结束，链表销毁成功！\n\n" NONE);
    system("pause");
}