#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "UBigNumber.h"

//输入无符号大数
struct UBigNumber InputUBN()
{
    struct UBigNumber result;
    _InitUBN(&result);

    char ch;
    ch = getchar();
    if (ch == '-')
    {
        result.symbol = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        _AppendDigit(&result, ch - '0'); //添加1位
        ch = getchar();
    }
    _Normalize(&result);
    return result;
}
//打印无符号大数
void PrintUBN(struct UBigNumber ubn)
{
    assert(ubn.digitCount > 0 && ubn.pHead->next != NULL); //断言 ： 至少有1位数字
    struct Node *la = ubn.pHead->next;                     //头结点无数据，跳过
    if (ubn.symbol == 1)
        printf("-");
    while (la)
    {
        if (la->digit != 0)
            break;
        la = la->next;
    }
    if (!la)
        printf("0");
    while (la)
    {
        printf("%d", la->digit);
        la = la->next;
    }
}
//两个无符号大数相加
struct UBigNumber AddUBN(struct UBigNumber *pA, struct UBigNumber *pB)
{
    struct UBigNumber result, *pResult = &result;
    _InitUBN(pResult);
    int iCarry = 0; //进位，初始0
    struct Node *p1, *p2;
    p1 = pA->pTail; //从低位开始处理
    p2 = pB->pTail;
    while (p1 != pA->pHead && p2 != pB->pHead) //两数相同位处理
    {
        int digit = p1->digit + p2->digit + iCarry;
        iCarry = digit / 10;               //新进位
        digit %= 10;                       //当前结果位
        _AppendFrontDigit(pResult, digit); //添加至结果最高位
        p1 = p1->prev;                     //准备处理前一位
        p2 = p2->prev;
    }
    while (p1 != pA->pHead) //第一大数剩余位处理
    {
        int digit = p1->digit + iCarry;
        iCarry = digit / 10;
        digit %= 10;
        _AppendFrontDigit(pResult, digit);
        p1 = p1->prev;
    }
    while (p2 != pB->pHead) //第二大数剩余位处理
    {
        int digit = p2->digit + iCarry;
        iCarry = digit / 10;
        digit %= 10;
        _AppendFrontDigit(pResult, digit);
        p2 = p2->prev;
    }
    if (iCarry != 0) //最后进位处理
        _AppendFrontDigit(pResult, iCarry);
    return result;
}
//两个无符号大数相减
struct UBigNumber MinUBN(struct UBigNumber *pA, struct UBigNumber *pB)
{
    struct UBigNumber result, *pResult = &result;
    _InitUBN(pResult);
    int iCarry = 0; //进位，初始0
    struct Node *p1, *p2;
    p1 = pA->pTail; //从低位开始处理
    p2 = pB->pTail;
    while (p1 != pA->pHead && p2 != pB->pHead) //两数相同位处理
    {
        int digit = p1->digit - p2->digit + iCarry;
        iCarry = 0;
        while (digit < 0)
        {
            digit += 10;
            iCarry--;
        }
        _AppendFrontDigit(pResult, digit); //添加至结果最高位

        p1 = p1->prev; //准备处理前一位
        p2 = p2->prev;
    }
    while (p1 != pA->pHead) //第一大数剩余位处理
    {
        int digit = p1->digit + iCarry;
        iCarry = 0;
        while (digit < 0)
        {
            digit += 10;
            iCarry--;
        }
        _AppendFrontDigit(pResult, digit);
        p1 = p1->prev;
    }
    while (p2 != pB->pHead) //第二大数剩余位处理
    {
        int digit = p2->digit + iCarry;
        iCarry = 0;
        while (digit < 0)
        {
            digit += 10;
            iCarry--;
        }
        _AppendFrontDigit(pResult, digit);
        p2 = p2->prev;
    }
    return result;
}

//销毁无符号大数，释放空间
void DestoryUBN(struct UBigNumber *pUBN)
{
    while (pUBN->pHead != NULL) //清空后应该只剩一个头结点
    {
        struct Node *p = pUBN->pHead; //待删除结点
        pUBN->pHead = p->next;        //尾指针前移
        free(p);                      //释放结点
    }
}
//建立表示无符号大数用带头结点双链表
void _InitUBN(struct UBigNumber *pUBN)
{
    struct Node *p = _NewNode();
    pUBN->pHead = pUBN->pTail = p; //建头结点
    p->next = p->prev = NULL;
    pUBN->digitCount = 0; //位数0
    pUBN->symbol = 0;     //正数
}
//无符号大数尾部添加一位数
void _AppendDigit(struct UBigNumber *pUBN, int digit)
{
    if (pUBN->digitCount == 1 && pUBN->pTail->digit == 0) //原只有一个高位0
    {
        pUBN->pTail->digit = digit; //位数不变，数值为0
        return;
    }
    struct Node *p = _NewNode(); //申请新结点
    p->digit = digit;            //设置结点数值
    p->next = NULL;              //修改双链表，添加成为新尾部结点
    p->prev = pUBN->pTail;
    pUBN->pTail->next = p;
    pUBN->pTail = p;
    ++pUBN->digitCount; //修改位数
}
//无符号大数前添加一位数
void _AppendFrontDigit(struct UBigNumber *pUBN, int digit)
{
    struct Node *p = _NewNode(); //申请新结点
    p->digit = digit;            //设置结点数值
    p->next = pUBN->pHead->next; //修改双链表，添加在头结点后
    if (p->next != NULL)
        p->next->prev = p;
    p->prev = pUBN->pHead;
    pUBN->pHead->next = p;
    if (pUBN->pTail == pUBN->pHead)
        pUBN->pTail = p; //原先只有头结点时，新结点也是尾结点
    ++pUBN->digitCount;  //修改位数
}
//无符号大数规范表示，去除高位多余0，至少含一位数字
void _Normalize(struct UBigNumber *pUBN)
{
    if (pUBN->digitCount == 0)
        _AppendDigit(pUBN, 0);
    while (pUBN->digitCount > 1 && pUBN->pHead->next->digit == 0) //去除高位多余的0
    {
        struct Node *p;
        p = pUBN->pHead->next;       //待删除的结点
        pUBN->pHead->next = p->next; //正向链表中删除
        p->next->prev = pUBN->pHead; //反向链表中删除
        free(p);                     //释放结点
        --pUBN->digitCount;          //调整位数
    }
}

//pa>pb返回 1，pa<pb返回-1，pa=pb返回0
int Compare(struct UBigNumber *pa, struct UBigNumber *pb)
{
    if (pa->digitCount != pa->digitCount)
        return pa->digitCount - pb->digitCount;
    struct Node *p1, *p2;
    p1 = pa->pHead;
    p2 = pb->pHead;
    while (p1)
    {
        if (p1->digit != p2->digit)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
            return p1->digit > p2->digit ? 1 : -1;
    }
    return 0;
}
//动态分配一个结点，返回结点指针
//分配失败时，简化程序，退出运行
struct Node *_NewNode()
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) //分配失败
    {
        printf("Error : out of memory\n");
        exit(-1); //简化程序，退出运行
    }
    return p;
}