#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

void EnQueue(arrayqueue Q, ELementType item)
{
    if(Q->front == (Q->rear+1) % MAXSIZE)
    {
        printf("Queue is full!\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MAXSIZE; 
    Q->Data[Q->rear] = item;
}

ELementType DeQueue(arrayqueue Q)
{
    if(Q->front == Q->rear)
    {
        printf("Queue is empty!\n");
        return ERROR;
    }
    Q->front = (Q->front + 1) % MAXSIZE;
    return Q->Data[Q->front];
}