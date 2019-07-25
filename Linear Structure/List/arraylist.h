#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#define MAXSIZE 100

typedef int ElementType;
typedef int Position;
typedef struct aLNode *aList;

struct aLNode{
	ElementType Data[MAXSIZE];
	Position Last;
};

aList MakeEmpty();
Position Find(ElementType X, aList PtrL);
void Insert( ElementType X,	Position p, aList PtrL );
void Delete( Position p, aList PtrL );

#endif
