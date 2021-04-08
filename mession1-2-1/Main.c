#include "LinkList.c"
#include "Color.h"
#include "Read.h"
const int inf = ~0u >> 2;
int main()
{
    system("cls");
    printf(LIGHT_BLUE "请输入圆桌上的人数M[1,100000]：" NONE);
    int m = Read(1, 100000);
    printf(LIGHT_PURPLE "请输入报数的最大值N[1,100000]：" NONE);
    int n = Read(1, 100000);
    printf(LIGHT_GREEN "请输入报数的最大值K[1,100000]：" NONE);
    int k = Read(1, 100000);
    n--;
    k--;
    LinkList listA = Create(m); //返回的是尾节点
    LinkList listB = (LinkList)malloc(sizeof(ListNode));
    LinkList FrontB = listB;
    int i = 0;
    int j = 0;

    //第一次
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < n % m; j++)
            listA = listA->next;
        LinkList del = listA->next;
        listA->next = del->next;//从A中删去del
        listB->next = del;//在B中加入del
        listB = listB->next;//将B修改为B的尾指针
    }
    listB->next = FrontB->next;//将B的尾指针指向B的首元素
    free(FrontB);//释放掉无意义的头部

    //第二次
    printf(LIGHT_RED "最终的队列为：" NONE);
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < k % m; j++)
            listB = listB->next;
        LinkList del = listB->next;
        listB->next = del->next;
        printf("%d  ", del->data);
        free(del);
    }
    puts("\n");
    system("pause");
}