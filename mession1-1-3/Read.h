#ifndef Read_H
#define Read_H
#include "HeadFile.h"
int Read(int left, int right) //读入一个int属于[left,right]
{
    while (1)
    {
        int object = 0;
        fflush(stdin);
        if (scanf("%d", &object) && object >= left && object <= right)
        {
            puts("");
            return object;
        }
        puts("");
        printf(RED "Input Error!Please input again!range:[%d,%d]\n\n" NONE, left, right);
        printf(RED "Please input again:" NONE);
    }
}
#endif