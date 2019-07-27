#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

ElementType Dequeue(linkqueue Q)
{
    List tempNode;
    ElementType item;
    if(!Q->front)
    {
        printf("Queue is empty!\n");
        return ERROR;
    }
    tempNode = Q->front;
    if(Q->front ==Q->rear)
        Q->front = Q->rear = NULL;
    else
        Q->front = tempNode->Next;
    item = tempNode->Data;
    free(tempNode);
    return item;
}

void Enqueue(linkqueue Q, ElementType item)
{
    List S = (List)malloc(sizeof(struct Node));
    S->Data = item;
    S->Next = NULL;
    Q->rear->Next = S;
    Q->rear = S;
}