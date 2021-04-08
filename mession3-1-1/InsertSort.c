#include "HeadFile.h"

void insertSort(int *a, int len)
{
    int i, j;
    for (i = 1; i < len; i++)
    {
        if (a[i] < a[i - 1])
        {
            j = i - 1;
            int x = a[i];
            while (j > -1 && x < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;
        }
    }
}