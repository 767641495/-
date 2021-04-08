#include "LinkList.c"
#include "Color.h"
#include "Read.h"
const int inf = ~0u >> 2;
int main()
{
    system("cls");
    printf(LIGHT_BLUE "请输入圆桌上的人数M[1,100000]：" NONE);
    int m = Read(1, 100000);
    printf(LIGHT_PURPLE "请输入若干正整数[1,100000]：" NONE);
    int n,i,j;
    LinkList listA = Create(m); //返回的是尾节点
    LinkList listB = (LinkList)malloc(sizeof(ListNode));
    LinkList temp = listB;
    while (~scanf("%d", &n))
    {
        n--;
        
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n % m; j++)
                listA = listA->next;
            LinkList del = listA->next;
            listA->next = del->next; //从A中删去del
            listB->next = del;       //在B中加入del
            listB = listB->next;     //将B修改为B的尾指针
        }
        listB->next = temp->next; //将B的尾指针指向B的首元素

        //交换AB指针
        listA = listB;
        listB = temp;
    }
    free(temp);
    printf(LIGHT_RED "最终的队列为：" NONE);
    listA = listA->next;
    for (i = 0; i < m; i++)
    {
        printf("%d  ", listA->data);
        temp = listA;
        listA = listA->next;
        free(temp);
    }
    puts("\n");
    system("pause");
}