#include <stdio.h>
#include "UBigNumber.c"

int main ()
{   struct UBigNumber A, B, C, D;
    A = InputUBN (); //无符号大数输入
    B = InputUBN ();
    C = AddUBN (&A, &B); //无符号大数相加
    D = MinUBN (&A, &B);

    PrintUBN (A);
    printf (" + ");
    PrintUBN (B);
    printf (" = ");
    PrintUBN (C);
    puts("");

    PrintUBN (A);
    printf (" - ");
    PrintUBN (B);
    printf (" = ");
    PrintUBN (D);

    DestoryUBN (&A); //销毁无符号大数
    DestoryUBN (&B);
    DestoryUBN (&C);
    DestoryUBN (&D);
    return 0;
}