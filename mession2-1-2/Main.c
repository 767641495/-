#include "HeadFile.h"
#include "Recursion.c"
#include "NonRecursion.c"

int main()
{
    LinkQueue queue;
    InitQueue(&queue);
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    int **a = malloc(n * sizeof(int *));
    int **map = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        a[i] = malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
        map[i] = malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            map[i][j] = 0;
        }
    printf("非递归方法得到的结果：%d\n", NonRecursion(&queue,a,map,n,m));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            map[i][j] = 0;
    int ans = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ans += Recursion(a, map, n, m, i, j);
    printf("递归方法得到的结果：%d\n", ans);
}