#include <stdio.h>
#include <stdlib.h>
#include "mergeTwoLists.h"

List Merge( List L1, List L2 )
{
    List head, tail, temp;
    tail = (List)malloc(sizeof(struct Node));
    head = tail;
    while(L1 && L2)
    {
        if(L1->Data < L2->Data)
        {
            tail->Next = L1;
            tail = L1;
            L1 = L1->Next;
        }
        else
        {
            tail->Next = L2;
            tail = L2;
            L2 = L2->Next;
        }
    }
    tail->Next = L1 ? L1 : L2;
    temp = head;
    head = head->Next;
    free(temp);
    return head;
}