#include "HeadFile.h"

int Recursion(int **a, int **map, int n, int m, int i, int j)
{
    if (map[i][j] == 1)
        return 0;
    map[i][j] = 1;
    int k, nowx, nowy;
    for (k = 0; k < 4; k++)
    {
        nowx = i + cx[k];
        nowy = j + cy[k];
        if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && map[nowx][nowy] == 0 && a[nowx][nowy] == a[i][j])
            Recursion(a, map, n, m, nowx, nowy);
    }
    return 1;
}