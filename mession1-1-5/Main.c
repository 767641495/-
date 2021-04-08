#include "LinkList.c"
#include "Color.h"
#include "Read.h"
const int inf = ~0u >> 2;
int main()
{
    system("cls");
    printf(LIGHT_BLUE "请输入圆桌上的人数[1,100000]：" NONE);
    int n = Read(1, 100000);
    printf(LIGHT_PURPLE "请输入报数的最大值[1,100000]：" NONE);
    int m = Read(1, 100000);
    m--;
    LinkList list = Create(n); //返回的是尾节点
    int i = 0;
    printf(LIGHT_GREEN "他们出队列的顺序为：" NONE);
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m % n; j++)
            list = list->next;
        LinkList del = list->next;
        list->next = del->next;
        printf("%d  ", del->data);
        free(del);
    }
    puts("\n");
    system("pause");
}