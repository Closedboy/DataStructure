/*
 * 最大子列和2
 * 返回最大子列和以及该子列的首部索引和尾部索引
 * 在线处理算法
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct SubseqSum *pSubseqSum;
struct SubseqSum{
    int Sum;
    int first;
    int last;
};

pSubseqSum MaxSubseqSum( int A[], int N);

int main()
{
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N*sizeof(int));
    for( int i=0; i<N; i++ )
        scanf("%d", A+i);
    
    pSubseqSum mss = (pSubseqSum)malloc(sizeof(struct SubseqSum));
    mss = MaxSubseqSum( A, N );
    
    printf("%d %d %d\n", mss->Sum, mss->first, mss->last);

    return 0;
}

pSubseqSum MaxSubseqSum( int A[], int N)
{
    pSubseqSum mss = (pSubseqSum)malloc(sizeof(struct SubseqSum));
    mss->Sum = 0;
    mss->first = 0;
    mss->last = N - 1;
 	int ThisSum = 0;
	int tempf = 0;
    for( int i=0; i<N; i++ )
    {
        ThisSum += A[i];
        if( ThisSum > mss->Sum )
        {
            mss->Sum = ThisSum;
			mss->first = tempf;
            mss->last = i;
        }
        else if( ThisSum < 0)
        {
            ThisSum = 0;
            tempf = i + 1;
        }
    }
	return mss;
}

