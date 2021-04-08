#include <stdio.h>
#include "UBigNumber.c"

int main()
{
    struct UBigNumber A, B, C, D;
    A = InputUBN(); //无符号大数输入
    B = InputUBN();

    //符号相同
    if (A.symbol == B.symbol)
    {
        PrintUBN(A);
        printf(" + ");
        PrintUBN(B);
        printf(" = ");
        if (A.symbol == 1)
            printf("-");
        PrintUBN(C = AddUBN(&A, &B));
    }
    //符号不同
    else
    {
        PrintUBN(A);
        printf(" + ");
        PrintUBN(B);
        printf(" = ");

        switch (Compare(&A, &B))
        {
        case 0:
        case 1:
            if (A.symbol == 1)
                printf("-");
            PrintUBN(C = MinUBN(&A, &B));
            break;
        case -1:
            if (B.symbol == 1)
                printf("-");
            PrintUBN(C = MinUBN(&A, &B));
            break;
        }
    }
    puts("");

    PrintUBN(A);
    printf(" - ");
    PrintUBN(B);
    printf(" = ");

    //符号不同
    if (A.symbol != B.symbol)
    {
        if (A.symbol == 1)
            printf("-");
        PrintUBN(D = AddUBN(&A, &B));
    }
    //符号相同
    else
    {
        switch (Compare(&A, &B))
        {
        case 1:
            if (B.symbol == 0)
                printf("-");
            PrintUBN(D = MinUBN(&A, &B));
            break;
        case -1:
            if (A.symbol == 0)
                printf("-");
            PrintUBN(D = MinUBN(&B, &A));
            break;
        default:
            printf("0");
            break;
        }
    }
    puts("");

    DestoryUBN(&A); //销毁无符号大数
    DestoryUBN(&B);
    DestoryUBN(&C);
    DestoryUBN(&D);
    return 0;
}