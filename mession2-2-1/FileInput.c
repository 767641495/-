#include "HeadFile.h"

int Fileinput()
{
    FILE *fp;
    if ((fp = fopen("input.txt", "r")) == NULL)
    {
        fflush(stdin);
        printf("输入文件不存在!\n请创建一个\"input.txt\"文件！\n");
        system("pause");
        return -1;
    }
    fscanf(fp, "%d%d", &M, &N);
    fscanf(fp, "%d%d", &start.x, &start.y);
    fscanf(fp, "%d%d", &end.x, &end.y);
    for (i = 0; i <= M - 1; i++)
    {
        for (j = 0; j <= N - 1; j++)
        {
            Maze[i][j] = -1;
            if (fscanf(fp, "%d", &Maze[i][j]) == EOF || (Maze[i][j] != 0 && Maze[i][j] != 1))
                return -1;
        }
        ch = ' ';
        fscanf(fp, "%c", &ch);
        if (i != M - 1 && ch != '\n')
            return -1;
    }
    int temp;
    if (fscanf(fp, "%d", &temp) != EOF)
    {
        fclose(fp);
        system("cls");
        printf("该迷宫不合法!\n请按下列要求修改txt文件后再读取迷宫\n");
        puts("迷宫第一行输入行和列，中间以空格分隔；");
        puts("迷宫第二行输入起点与终点的横纵坐标，中间以空格分隔；");
        puts("用1表示墙，0表示路；");
        puts("列与列之间以空格分隔，行与行之间换行符分隔，每行末尾没有多余空格；");
        puts("迷宫末尾没有冗余信息。");
        system("pause");
        return -1;
    }
    return 1;
}
