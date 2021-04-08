#include "HeadFile.h"
#include "Stack.h"
#include "Print.c"

void DFS(PosType now, PosType end, SqStack *s)
{
	int i;
	if (count == 1)
		return;
	if (now.x == end.x && now.y == end.y)
	{
		count = 1;
		puts(YELLOW "添加路径后的地图为:\n" NONE);
		PrintMaze();
		puts(YELLOW "找到路径:" NONE);
		PrintPath(s);
		puts("");
		return;
	}
	for (i = 1; i <= 4; i++)
	{
		if (count == 1)
			return;
		SElemType nextpos;
		nextpos.seat = NextPos(now, i);
		vis[now.x][now.y] = i;
		if (!Judge(nextpos.seat))
		{
			if (i == 4)
			{
				vis[now.x][now.y] = -1;
				return;
			}
			continue;
		}
		vis[nextpos.seat.x][nextpos.seat.y] = 1;
		Push(s, nextpos);
		DFS(nextpos.seat, end, s);
		if (vis[nextpos.seat.x][nextpos.seat.y] != -1)
			vis[nextpos.seat.x][nextpos.seat.y] = 0;
		if (vis[nextpos.seat.x][nextpos.seat.y] == 0)
			vis[nextpos.seat.x][nextpos.seat.y] = -1;
		Pop(s, &nextpos);
	}
}