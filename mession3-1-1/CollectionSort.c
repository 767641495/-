#include "HeadFile.h"

void collectionSort(int *a,int len)
{
    int i, j;
    int MinIndex;  //保存最小的值的下标
    int buf;  //互换数据时的临时变量
    for (i=0; i<len-1; i++)
    {
        MinIndex = i;
        for (j=i+1; j<len; j++)  
            if (a[MinIndex] > a[j])
                MinIndex = j;
        if (MinIndex != i)
        {
            buf = a[MinIndex];
            a[MinIndex] = a[i];
            a[i] = buf;
        }
    }
}