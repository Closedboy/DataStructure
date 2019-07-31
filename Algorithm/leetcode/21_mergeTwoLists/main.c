#include <stdio.h>
#include <stdlib.h>
#include "mergeTwoLists.h"

List Read(); /* 读取链表 */
void Print( List L ); /* 打印链表 */

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = MergeRecursive(L1, L2);
    Print(L);
    return 0;
}

List Read()
{	
    int N;
  	List head, tail, p, temp;
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
    temp = head;
    head = head->Next;
	return head;
}

void Print( List L )
{
    if(L == NULL)
        printf("NULL");
    else
    {
        while(L)
        {
            printf("%d ", L->Data);
            L = L->Next;
        }
    }
    printf("\n");
}