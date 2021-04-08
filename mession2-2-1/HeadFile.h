#ifndef HeadFile_H
#define HeadFile_H
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
#define OK 1
#define stack_init_size 1050
#define stack_increment 10
typedef int Status;

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Color.h"

//常量
int M;	   //迷宫的行数
int N;	   //迷宫的列数
int P = 7; //随机生成迷宫的路和墙的期望比值(P:10-P)
int Maze[100 + 5][100 + 5], vis[100 + 5][100 + 5];
int count = 0;						 //路径总数
int dirr[6] = {0,1,2,3,4,1};						 //遍历顺序
int minlength = (100 + 5) * (100 + 5); //目前最小的路径长度
int maxread;						 //最大阅读路径数量
char ch;
int i,j;

#include "Stack.h"
PosType start, end;

#endif