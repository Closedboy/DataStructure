#include <stdio.h>
#include <stdlib.h>
#include "polylist.h"

int Compare(polyList a, polyList b)
{
	if(a->expon > b->expon)
		return 1;
	else if(a->expon == b->expon)
		return 0;
	else return -1;
}

void Attach(int coef, int expon, polyList *p)
{
	polyList newNode = (polyList)malloc(sizeof(struct polyNode));
	newNode->coef = coef;
	newNode->expon = expon;
	newNode->next = NULL;
	(*p)->next = newNode;
	*p = newNode;
}

polyList polyAdd(polyList a, polyList b)
{
	polyList sum, tail, pa, pb;
	sum = (polyList)malloc(sizeof(struct polyNode));
	tail = sum;
	pa = a->next;
	pb = b->next;
	while( pa && pb )
	{
		switch (Compare(pa, pb))
		{
		case 1:
			Attach(pa->coef, pa->expon, &tail);
			pa = pa->next;
			break;
		case 0:
			if(pa->coef + pb->coef)
				Attach(pa->coef + pb->coef, pa->expon, &tail);
			pa = pa->next;
			pb = pb->next;
			break;
		case -1:
			Attach(pb->coef, pb->expon, &tail);
			pb = pb->next;
			break;
		}
	}
	for(;pa;pa=pa->next)
		Attach(pa->coef, pa->expon, &tail);
	for(;pb;pb=pb->next)
		Attach(pb->coef, pb->expon, &tail);
	return sum;
}

void print(polyList a)
{
	polyList pa = a->next;
	if(!pa) printf("0 0");
	else
	{
		while(pa)
			{
				printf("%d %d", pa->coef, pa->expon);
				pa = pa->next;
				if(pa) printf(" ");
			}
	}
	printf("\n");
}

polyList Read()
{	
    int N, coef, expon;
  	polyList head, tail;
    head = (polyList)malloc(sizeof(struct polyNode));
    tail = head;
	scanf("%d", &N);
	while(N--)
    {   
		scanf("%d %d", &coef, &expon);
		Attach(coef, expon, &tail);
    }
	return head;
}

polyList polyMul(polyList a, polyList b)
{
	polyList head, tail, pa, pb, temph;
	head = (polyList)malloc(sizeof(struct polyNode));
	temph = (polyList)malloc(sizeof(struct polyNode));
	head->next = NULL;
	pa = a->next;
	while(pa)
	{
		tail = temph;
		pb = b->next;
		while(pb)
		{
			Attach(pa->coef*pb->coef, pa->expon+pb->expon, &tail);
			pb = pb->next;
		}
		head = polyAdd(temph, head);
		temph->next = NULL;
		pa = pa->next;
		free(temph);
	}
	return head;
}

int main()
{
	polyList L1, L2, L, sum;
    L1 = Read();
    L2 = Read();
 	sum = polyAdd(L1, L2);
    L = polyMul(L1, L2);
	print(sum);
    print(L);
    return 0;
}