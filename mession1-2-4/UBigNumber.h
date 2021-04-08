#ifndef UBIGNUMBER_H_INCLUDED
#define UBIGNUMBER_H_INCLUDED

struct Node
{
    int digit;                //数字
    struct Node *next, *prev; //前后结点指针
};
//无符号大数结构体
struct UBigNumber
{
    int digitCount;             //位数
    int symbol;                 //符号
    struct Node *pHead, *pTail; //指向头结点，尾结点
};
//下列函数返回的大数占用的内存资源由函数调用者负责释放
//输入无符号大数
struct UBigNumber InputUBN();
//打印无符号大数
void PrintUBN(struct UBigNumber ubn);
//两个无符号大数相加
struct UBigNumber AddUBN(struct UBigNumber *pA, struct UBigNumber *pB);
//销毁无符号大数，释放空间
void DestoryUBN(struct UBigNumber *pA);

//下列函数是无符号大数处理辅助函数
//建立表示无符号大数用带头结点双链表
void _InitUBN(struct UBigNumber *pUBN);
//无符号大数尾部添加一位数
void _AppendDigit(struct UBigNumber *pUBN, int digit);
//无符号大数前部添加一位数
void _AppendFrontDigit(struct UBigNumber *pUBN, int digit);
//无符号大数规范表示，去除高位多余0，至少含一位数字
void _Normalize(struct UBigNumber *pUBN);
//动态分配一个结点，返回结点指针
//分配失败时，简化程序，退出运行
struct Node *_NewNode();
#endif // UBIGNUMBER_H_INCLUDED