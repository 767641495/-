#include "HeadFile.h"

int Check(int *a, int len)
{
    int i;
    for (i = 1; i < len; i++)
        if (a[i] < a[i - 1])
            return 0;
    return 1;
}