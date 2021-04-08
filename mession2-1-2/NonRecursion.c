#include "HeadFile.h"

int NonRecursion(LinkQueue *q, int **a, int **map, int n, int m)
{
    int ans = 0;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
                continue;
            ans++;
            map[i][j] = 1;
            EnQueue(q, i, j);
            int x, y;
            while (q->front != q->rear)
            {
                DeQueue(q, &x, &y);
                int nowx, nowy;
                for (k = 0; k < 4; k++)
                {
                    nowx = x + cx[k];
                    nowy = y + cy[k];
                    if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && map[nowx][nowy] == 0 && a[nowx][nowy] == a[i][j])
                    {
                        EnQueue(q, nowx, nowy);
                        map[nowx][nowy] = 1;
                    }
                }
            }
        }
    }
    return ans;
}