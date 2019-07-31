#ifndef _POLYLIST_H
#define _POLYLIST_H

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

#endif