#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

aList MakeEmpty()
{
	aList PtrL;
	PtrL = (aList)malloc(sizeof(struct aLNode));
	PtrL->Last = -1;
	return PtrL;
}

Position Find( ElementType X, aList PtrL )
{
	for( int i=0; i<PtrL->Last; i++ )
	{
		if( PtrL->Data[i] == X ) return i;
	}
	return -1;
}

void Insert( ElementType X,	Position p, aList PtrL )
{
	if( PtrL->Last == MAXSIZE-1 )
	{
		printf("List is full!\n");
		return;
	}
	if( p < 1 || p > PtrL->Last+2 )
	{
		printf("invalid index!\n");
		return;
	}
	for( int i=PtrL->Last+1; i>p-1; i-- )
		PtrL->Data[i] = PtrL->Data[i-1];
	PtrL->Data[p-1] = X;
	PtrL->Last++;
	return;
}

void Delete( Position p, aList PtrL )
{
	if( p<1 || p>PtrL->Last+1 )
	{
		printf("invalid index!\n");
		return;
	}
	for( int i=p; i<=PtrL->Last; i++ )
		PtrL->Data[i-1] = PtrL->Data[i];
	PtrL->Last--;
	return;
}

