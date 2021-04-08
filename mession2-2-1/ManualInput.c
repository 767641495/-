#include "HeadFile.h"

int ManualInput()
{
    printf(LIGHT_BLUE "请输入迷宫的长[1,100];\n" NONE);
    M = Read(1, 100);
    printf(LIGHT_BLUE "请输入迷宫的宽[1,100];\n" NONE);
    N = Read(1, 100);
    printf(LIGHT_BLUE "请输入迷宫的入口位置的横坐标[0,%d];\n" NONE, M - 1);
    start.x = Read(0, M - 1);
    printf(LIGHT_BLUE "请输入迷宫的入口位置的纵坐标[0,%d];\n" NONE, N - 1);
    start.y = Read(0, N - 1);
    printf(LIGHT_BLUE "请输入迷宫的出口位置的横坐标[0,%d];\n" NONE, M - 1);
    end.x = Read(0, M - 1);
    printf(LIGHT_BLUE "请输入迷宫的出口位置的纵坐标[0,%d];\n" NONE, N - 1);
    end.y = Read(0, N - 1);

    printf(LIGHT_GREEN "请输入迷宫的通道和墙（用0或1表示）：\n" NONE, N - 1);
    for (i = 0; i <= M - 1; i++)
    {
        for (j = 0; j <= N - 1; j++)
        {
            Maze[i][j] = -1;
            scanf("%d", &Maze[i][j]);
            if (Maze[i][j] != 0 && Maze[i][j] != 1)
                return -1;
        }
    }
    puts("");
    return 1;
}
