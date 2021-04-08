#ifndef Stack_H
#define Stack_H
#include "HeadFile.h"

typedef struct PosType
{
	int x;
	int y;
} PosType;
typedef struct SElemType
{
	PosType seat; //坐标
	int di;		  //方向
} SElemType;
typedef struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;
Status GetTop(SqStack *s, SElemType *e) //获取栈顶元素
{
	if ((*s).top == (*s).base)
		return ERROR;
	*e = *((*s).top - 1);
	return OK;
}
Status InitStack(SqStack *s) //构造一个空栈
{
	(*s).base = (SElemType *)malloc(stack_init_size * sizeof(SElemType));
	if (!(*s).base)
		return OVERFLOW;
	(*s).top = (*s).base;
	(*s).stacksize = stack_init_size;
	return OK;
}
Status Pop(SqStack *s, SElemType *e) //出栈
{
	if ((*s).top == (*s).base)
		return ERROR;
	*e = *--(*s).top;
	return OK;
}
Status Push(SqStack(*s), SElemType e) //入栈
{
	if ((*s).top - (*s).base >= (*s).stacksize)
	{
		(*s).base = (SElemType *)realloc((*s).base, ((*s).stacksize + stack_increment) * sizeof(SElemType));
		if (!(*s).base)
			exit(OVERFLOW);
		(*s).top = (*s).base + (*s).stacksize;
		(*s).stacksize += stack_increment;
	}
	*(*s).top++ = e;
	return OK;
}
Status StackEmpty(SqStack s) //栈是否为空
{
	if (s.top == s.base)
		return OK;
	return OVERFLOW;
}
void StackClear(SqStack *s) //清空栈里所有元素
{
	SElemType temp;
	while (!StackEmpty((*s)))
		Pop(s, &temp);
}

Status Judge(PosType e) //判断是否可走
{
	if (e.x >= 0 && e.x < M && e.y >= 0 && e.y < N && (Maze[e.x][e.y] == 0 || Maze[e.x][e.y] == 3) && vis[e.x][e.y] == 0)
		return OK;
	return OVERFLOW;
}

PosType NextPos(PosType e, int dir) //下一步
{
	PosType E;
	switch (dirr[dir])
	{
	case 1:
		E.x = e.x;
		E.y = e.y + 1;
		break; //向右
	case 2:
		E.x = e.x + 1;
		E.y = e.y;
		break; //向下
	case 3:
		E.x = e.x;
		E.y = e.y - 1;
		break; //向左
	default:
		E.x = e.x - 1;
		E.y = e.y; //向上
	}
	return E;
}
#endif