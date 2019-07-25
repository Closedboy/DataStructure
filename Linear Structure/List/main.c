#include <stdio.h>
#include "arraylist.h"

int main()
{
	aList PtrL;
	ElementType X;
	Position p;
	int select;
	int i;
	while(1)
	{
		printf("-----------List control----------\n0:退出\t1:生成\t2:查找\t3:插入\t4:删除\t5:显示\n");
		scanf("%d", &select);
		switch(select){
		case 0:
			return 0;
		case 1:
			PtrL = MakeEmpty();
			printf("Input List Length: ");
			scanf("%d", &PtrL->Last);
			PtrL->Last--;
			printf("Input List element: ");
			for( i=0; i<=PtrL->Last; i++ )
				scanf("%d", PtrL->Data+i);
			break;
		case 2:
			printf("Input search element: ");
			scanf("%d", &X);
			p = Find( X, PtrL);
			printf("%d\n", p);
			break;
		case 3:
			printf("insert position: ");
			scanf("%d", &p);
			printf("insert element: ");
			scanf("%d", &X);
			Insert( X, p, PtrL);
			break;
		case 4:
			printf("delete position: ");
			scanf("%d", &p);
			Delete( p, PtrL );	
			break;
		case 5:
			for( int i=0; i<=PtrL->Last; i++ )
				printf("%d ", *(PtrL->Data+i) );
			printf("\n");
			break;
		}
	}
	return 0;
}
