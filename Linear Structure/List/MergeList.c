// 02-线性结构1 两个有序链表序列的合并 (15 分)
// 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

// 函数接口定义：
// List Merge( List L1, List L2 );
// 其中List结构定义如下：

// typedef struct Node *PtrToNode;
// struct Node {
//     ElementType Data; /* 存储结点数据 */
//     PtrToNode   Next; /* 指向下一个结点的指针 */
// };
// typedef PtrToNode List; /* 定义单链表类型 */
// L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。
// 应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{	
    int N;
  	List head, tail, p;
    head = (List)malloc(sizeof(struct Node));
    tail = head;
	scanf("%d", &N);
	while(N--)
    {
        p = (List)malloc(sizeof(struct Node));
		scanf("%d", &(p->Data));
        p->Next = NULL;
        tail->Next = p;
        tail = p;
    }
	return head;
}

void Print( List L )
{
    if(L->Next == NULL)
        printf("NULL");
    else
    {
        List p = L->Next;
        while(p)
        {
            printf("%d ", p->Data);
            p = p->Next;
        }
    }
    printf("\n");
}

List Merge( List L1, List L2 )
{
    List head, tail, pL1, pL2;
    tail = (List)malloc(sizeof(struct Node));
    head = tail;
    pL1 = L1->Next;
    pL2 = L2->Next;
    while(pL1 && pL2)
    {
        if(pL1->Data < pL2->Data)
        {
            tail->Next = pL1;
            tail = pL1;
            pL1 = pL1->Next;
        }
        else
        {
            tail->Next = pL2;
            tail = pL2;
            pL2 = pL2->Next;
        }
    }
    tail->Next = pL1 ? pL1 : pL2;
    L1->Next = NULL;
    L2->Next = NULL;
    return head;
}