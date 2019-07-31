/*
02-线性结构2 一元多项式的乘法与加法运算 (20 分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *polyList;
struct polyNode{
	int coef;
	int expon;
	polyList next;
};

polyList polyAdd(polyList a, polyList b);
polyList polyMul(polyList a, polyList b);
void print(polyList a);
int Compare(polyList a, polyList b);
void Attach(int coef, int expon, polyList* p);
polyList Read();

int main()
{
	polyList L1, L2, L, sum;
    L1 = Read();
    L2 = Read();
 	sum = polyAdd(L1, L2);
    L = polyMul(L1, L2);
    print(L);
	print(sum);
    return 0;
}

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
	if(!pa)
		printf("0 0");
	else
	{
		while(pa)
			{
				printf("%d %d", pa->coef, pa->expon);
				pa = pa->next;
                if(pa)
                    printf(" ");
			}
	}
	printf("\n");
}

polyList Read()
{	
    int N;
  	polyList head, tail, p;
    head = (polyList)malloc(sizeof(struct polyNode));
    tail = head;
	scanf("%d", &N);
	while(N--)
    {
        p = (polyList)malloc(sizeof(struct polyNode));
		scanf("%d", &(p->coef));
		scanf("%d", &(p->expon));
        p->next = NULL;
        tail->next = p;
        tail = p;
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
	}
	return head;
}
