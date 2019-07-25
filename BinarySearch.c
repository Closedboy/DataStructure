#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput();
Position BinarySearch( List L, ElementType X );

int main()
{
  	List L = (List)malloc(sizeof(struct LNode));
    ElementType X;
    Position P;

	L = ReadInput();
	scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{	
  	List L = (List)malloc(sizeof(struct LNode));
	scanf("%d", &L->Last);
	for( int i=1; i<=L->Last; i++ )
		scanf("%d", L->Data+i);
	return L;
}

Position BinarySearch( List L,  ElementType X )
{
    Position left, right, center;
    left = 1;
    right = L->Last;
    while( right - left != 1 )
    {
        center = ( left + right ) / 2;
		if( L->Data[center] == X )
			return center;
        else if( L->Data[center] > X )
            right = center;
        else
            left = center;
    }
	if( L->Data[left] == X )
    	return left;
	else if( L->Data[right] == X )
		return right;
	else return NotFound;
}
