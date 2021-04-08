#include "HeadFile.h"

void createArray(int *a,int len)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < len;i++)
        a[i] = rand() % len;
}