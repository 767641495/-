#include "HeadFile.h"
#include "Menu.c"
#include "CreateArray.c"
#include "BubbleSort.c"
#include "CollectionSort.c"
#include "InsertSort.c"
#include "Mergesort.c"
#include "Check.c"
#include "Print.c"

int main()
{
    int *a = malloc(100005 * sizeof(int));
    int *L = malloc(100005 * sizeof(int));
    int *R = malloc(100005 * sizeof(int));
    int i, j;
    for (i = 1; i <= 4; i++)
        for (j = 1; j <= 4; j++)
            Time[i][j] = -1;
    while (1)
    {
        Menu();
        printf("请输入您的选择:");
        int option = 0;
        option = Read(1, 6);
        if (option == 5)
        {
            printTimeTable();
            continue;
        }
        else if (option == 6)
        {
            free(a);
            free(L);
            free(R);
            puts(LIGHT_BLUE "程序已退出！\n感谢您的使用！\n" NONE);
            puts("洪智豪 19195216\n");
            system("pause");
            return 0;
        }
        system("cls");
        FILE *fp;
        fp = fopen("Data.txt", "w");
        for (i = 100, j = 1; i <= 100000; i *= 10, j++)
        {
            createArray(a, i);
            time_t ltime1, ltime2;
            struct _timeb tstruct1, tstruct2;
            _ftime(&tstruct1);
            time(&ltime1);

            switch (option)
            {
            case 1:
                bubbleSort(a, i);
                break;
            case 2:
                collectionSort(a, i);
                break;
            case 3:
                insertSort(a, i);
                break;
            case 4:
                mergesort(a, L, R, 0, i - 1);
                break;
            }
            time(&ltime2);
            _ftime(&tstruct2);
            if (Check(a, i) == 1)
                printf(LIGHT_RED "排序结果正确！\n");
            else
                printf(LIGHT_RED "排序结果错误！\n");
            Time[option][j] = (ltime2 * 1000 + tstruct2.millitm) - (ltime1 * 1000 + tstruct1.millitm);
            printf(LIGHT_PURPLE "程序耗时：%ld微秒\n\n" NONE, Time[option][j]);
        }
        fclose(fp);
        system("pause");
    }
}