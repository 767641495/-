#include "Stack.h"
#include "LQueue.h"

int main()
{
    SqStack stack;
    LinkQueue queue;
    int num;
    InitStack(&stack);
    InitQueue(&queue);
    while (~scanf("%d", &num))
    {
        if(num > 0)
            Push(&stack, num);
        else if(num < 0)
            EnQueue(&queue, num);
    }
    ShowStack(&stack);
    ShowQueue(&queue);
    system("pause");
}