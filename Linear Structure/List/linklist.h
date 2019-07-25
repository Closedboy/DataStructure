#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int ElementType;
typedef int Position;
typedef struct lLNode *lList;

struct lLNode{
	ElementType Data;
	lList Next;
};

int Length( lList PtrL );
lList FindKth( Position K, lList PtrL );
lList Find( ElementType X, lList PtrL );
lList Insert( ElementType X, Position K, lList PtrL );
lList Delete( Position K, lList PtrL );
void display( lList PtrL );

#endif
