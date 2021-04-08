#include "HeadFile.h"
#include "BinaryRecursion.c"
#include "BinaryNonRecursion.c"

int main()
{
    int n, i = 0;
    int minNum, maxNum;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    while (i < n)
    {
        scanf("%d", &a[i]);
        i++;
    }
    binaryFindMinMax(a, 0, n - 1, &minNum, &maxNum);
    printf("递归方法获得的最小值为%d，最大值为 %d；\n", minNum, maxNum);
    BinaryFindMinMax(a, 0, n - 1, &minNum, &maxNum, n);
    printf("非递归方法获得的最小值为%d，最大值为 %d；", minNum, maxNum);
}