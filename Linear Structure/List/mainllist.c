#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
	lList PtrL,p;
	ElementType X;
	Position K;
	int select;
	int i;
	while(1)
	{
		printf("-----------List control----------\n0:退出\t1:生成\t2:查找\t3:插入\t4:删除\t5:显示\n");
		scanf("%d", &select);
		switch(select){
		case 0:
			free(PtrL);
			return 0;
		case 1:
			PtrL = (lList)malloc(sizeof(struct lLNode));
			PtrL->Next = NULL;
			printf("Input List element: ");
			scanf("%d", &PtrL->Data);
			break;
		case 2:
			printf("Input search element: ");
			scanf("%d", &X);
			p = Find( X, PtrL);
			if(p == NULL) printf("No exist!\n");
			else printf("%d\n", p->Data);
			break;
		case 3:
			printf("insert position: ");
			scanf("%d", &K);
			printf("insert element: ");
			scanf("%d", &X);
			PtrL = Insert( X, K, PtrL);
			break;
		case 4:
			printf("delete position: ");
			scanf("%d", &K);
			PtrL = Delete( K, PtrL );	
			break;
		case 5:
			display(PtrL);
			printf("\n");
			break;
		}
	}
	free(PtrL);
	free(p);
	return 0;
}
