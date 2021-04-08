#include "HeadFile.h"
#include "Read.h"
#include "FileInput.c"
#include "ManualInput.c"
#include "Menu.c"
#include "Dfs.c"
#include "Exit.c"

int main()
{
	SqStack S;
	InitStack(&S);
	while (1)
	{
		Menu();
		printf("请输入您的选择:");
		int option = 0;
		option = Read(1, 3);
		system("cls");
		if (option == 3)
		{
			Exit();
			return 0;
		}
		if (option == 1 && Fileinput() == -1 || option == 2 && ManualInput() == -1)
		{
			printf(RED "您未按照规范输入！！！" NONE);
			system("pause");
			continue;
		}
		puts("迷宫输入成功！");
		PrintMaze();
		DFS(start, end, &S);
		if (count == 0)
		{
			fflush(stdin);
			printf(RED "该迷宫无解!!\n请修改您的迷宫！\n" NONE);
			system("pause");
			continue;
		}
		else
		{
			StackClear(&S);
			memset(vis, 0, sizeof(vis));
			puts(LIGHT_PURPLE "路径显示完毕！\n" NONE);
		}
		memset(vis, 0, sizeof(vis));
		count = 0;
		fflush(stdin);
		system("pause");
	}
}