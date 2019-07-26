#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

linkstack CreateStack()
{
    linkstack S;
    S = (linkstack)malloc(sizeof(struct lSNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(linkstack S)
{
    return ( S->Next == NULL );
}

void Push(linkstack S, ELementType item)
{
    linkstack temp;
    temp = (linkstack)malloc(sizeof(struct lSNode));
    temp->Data = item;
    temp->Next = S->Next;
    S->Next = temp;
}

ELementType Pop(linkstack S)
{
    ELementType TopItem;
    if(IsEmpty(S))
    {
        printf("Stack is empty!\n");
        return ERROR;
    }
    else
    {
        linkstack temp;
        temp = S->Next;
        S->Next = temp->Next;
        TopItem = temp->Data;
        free(temp);
        temp = NULL;
        return TopItem;
    }
}
