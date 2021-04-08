#include "HeadFile.h"

void printTimeTable()
{
    int i,j;
    printf("                      100       10000     100000    100000\n");
    for (i = 1; i <= 4; i++)
    {
        switch (i)
        {
        case 1:
            printf("冒泡排序耗时(us)：    ");
            break;
        case 2:
            printf("简单选择排序耗时(us)：");
            break;
        case 3:
            printf("简单插入排序耗时(us)：");
            break;
        case 4:
            printf("归并排序耗时(us)：    ");
            break;
        }
        if (Time[i][1] != -1)
            for (j = 1; j <= 4; j++)
                printf("%-10ld", Time[i][j]);
        else
            printf("NULL      NULL      NULL      NULL");
        puts("\n");
    }
    system("pause");
}