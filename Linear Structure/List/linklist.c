#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int Length( lList PtrL )
{
	int i = 0;
	lList p = PtrL;
	while(p)
	{
		p = p->Next;
		i++;
	}
	return i;
}

lList FindKth( Position K, lList PtrL )
{
	lList p = PtrL;
	int i = 1;
	while( p != NULL && i < K )
	{
		p = p->Next;
		i++;
	}
	if( i == K ) return p;
	else return NULL;
}

lList Find( ElementType X, lList PtrL )
{
	lList p = PtrL;
	while( p != NULL && p->Data != X )
		p = p->Next;
	return p;
}

lList Insert( ElementType X, Position K, lList PtrL )
{
	lList p, s;
	s = (lList)malloc(sizeof(struct lLNode));
	s->Data = X;
	if( K == 1)
	{
		s->Next = PtrL;
		return s;
	}
	else
	{
		p = FindKth( K-1, PtrL );
		if( p == NULL ) printf("K is invalid!\n");
		else
		{
			s->Next = p->Next;
			p->Next = s;
		}
		return PtrL;
	}
}

lList Delete( Position K, lList PtrL )
{
	lList p, s;
	if( PtrL == NULL ) return NULL;
	else if( K == 1)
	{
		s = PtrL;
		PtrL = PtrL->Next;
		free(s);
	}
	else
	{
		p = FindKth( K-1, PtrL );
		if( p == NULL ) printf("%dth is not exist!\n", K-1);
		else if( p->Next == NULL ) printf("%dth is not exist!\n", K);
		else 
		{
			s = p->Next;
			p->Next = s->Next;
			free(s);
		}
	}
	return PtrL;
}

void display( lList PtrL )
{
	lList p = PtrL;
	while(p)
	{
		printf("%d->", p->Data);
		p = p->Next;
	}
}
