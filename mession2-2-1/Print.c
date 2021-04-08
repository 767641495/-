#include "HeadFile.h"
#include "Stack.h"

void PrintPath(SqStack *s) //打印路径
{
	int isFirst = TRUE;
	SqStack TempStack;
	InitStack(&TempStack);
	SElemType TempValue;
	while (!StackEmpty((*s)))
	{
		Pop(s, &TempValue);
		Push(&TempStack, TempValue);
	}
	while (!StackEmpty((TempStack)))
	{
		Pop(&TempStack, &TempValue);
		Push(s, TempValue);
		if (isFirst)
			isFirst = FALSE;
		else
			printf(LIGHT_RED " -> " NONE);
		printf(GREEN "(%d,%d)" NONE, TempValue.seat.x, TempValue.seat.y);
	}
	puts("\n");
}

void PrintMaze() //打印迷宫
{
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (Maze[i][j] == 4)
			{
				printf("×");
				continue;
			}
			if (Maze[i][j] == 3)
			{
				printf("●");
				continue;
			}
			if (Maze[i][j] == 2)
			{
				printf("○");
				continue;
			}
			if (Maze[i][j] == 0 && vis[i][j] > 0)
			{
				switch (vis[i][j])
				{
				case 1:
					printf("→");
					break;
				case 2:
					printf("↓");
					break;
				case 3:
					printf("←");
					break;
				case 4:
					printf("↑");
				}
			}
			else if (vis[i][j] == -1)
				printf("□"); //不通的路
			else if (Maze[i][j] == 1)
				printf("■"); //迷宫的墙
			else
				printf("□"); //迷宫未走的路
		}
		puts("");
	}
	puts("");
}