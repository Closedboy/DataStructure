/* 
 * C Program
 * Data Structure
 * ------------------------------------------------1.Maximum Subsequence Sum--------------------------------------------------
 * 给定K个整数组成的序列，{Ni-Nk},“连续子列”被定义为{Ni-Nj},。“最大子列和”则被定义为所有连续子列元素的和中最大者。
 * 例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。
 *
 * 本题旨在测试各种不同的算法在各种数据情况下的表现。
 * 输入格式:
 * 输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
 *
 * 输出格式:
 * 在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
*/
#include <stdio.h>

int MaxSubseqSum1( int A[], int N );
int MaxSubseqSum2( int A[], int N );
int Max3( int a, int b, int c );
int DivideAndConquer( int A[], int left, int right );
int MaxSubseqSum3( int A[], int N );
int MaxSubseqSum4( int A[], int N );

int main()
{
	int result;
	int N = 6;
	int A[] = {-2, 11, -4, 13, -5, -2};
	result = MaxSubseqSum4(A, N);
	printf("%d\n", result);
	return 0;
}

/* 
 * Algorithm 1
 * 遍历子列首部和尾部，计算每个子列的和 
*/
int MaxSubseqSum1( int A[], int N )
{
	int MaxSum = 0;
	int left, right, seqNum;
	for( left=0; left<N; left++ )
	{
		for( right=left; right<N; right++ )
		{
			int ThisSum = 0;
			for( seqNum=left; seqNum<right; seqNum++ )
				ThisSum += A[seqNum];
			if( ThisSum > MaxSum )
				MaxSum = ThisSum;
		}
	}
	if( MaxSum > 0 ) return MaxSum;
	else return 0;
}

/* 
 * Algorithm 2
 * 避免重复计算i-j的和 
*/
int MaxSubseqSum2( int A[], int N )
{
	int MaxSum = 0;
	int left, right, seqNum;
	for( left=0; left<N; left++ )
	{
		int ThisSum = 0;
		for( right=left; right<N; right++ )
		{
			ThisSum += A[right];
			if( ThisSum > MaxSum )
				MaxSum = ThisSum;
		}
	}
	if( MaxSum > 0 ) return MaxSum;
	else return 0;
}

/* 
 * Algorithm 3
 * 分而治之
 * T(N) = 2 * T(N/2) + cN
 * 		= 2 * (2 * T(N/4) + cN/2) + cN
 *		= 2^k * T(1) + ckN
 * let 2^k = N
 * T(N) = O(N) + O(NlogN)
*/

int Max3( int a, int b, int c)
{
	return  a > b ? a > c ? a: c : b > c ? b : c;
}

int DivideAndConquer( int A[], int left, int right )
{
	int MaxLeftSum, MaxRightSum;
	int LeftBorderSum, RightBorderSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int center, i;
	
	if( left == right) return A[left] > 0 ? A[left] : 0;

	/* Divide*/
	center = ( left + right ) / 2;
	MaxLeftSum = DivideAndConquer( A, left, center );
	MaxRightSum = DivideAndConquer( A, center+1, right );
	
	/* Conquer */
	LeftBorderSum = 0; MaxLeftBorderSum = 0;
	for( i=center; i>=left; i-- )
	{
		LeftBorderSum += A[i];
		if( LeftBorderSum > MaxLeftBorderSum )
			MaxLeftBorderSum = LeftBorderSum;
	}
	RightBorderSum = 0; MaxRightBorderSum = 0;
	for( i=center+1; i<=right; i++ )
	{
		RightBorderSum += A[i];
		if( RightBorderSum > MaxRightBorderSum )
			MaxRightBorderSum = RightBorderSum;
	}
	
	return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int A[], int N )
{
	return DivideAndConquer( A, 0, N-1 ); 
}

/* 
 * Algorithm 4
 * 在线处理 
*/
int MaxSubseqSum4( int A[], int N )
{
	int ThisSum = 0;
	int MaxSum = 0;
	int i;
	for( i=0; i<N; i++ )
	{
		ThisSum += A[i];
		if( ThisSum > MaxSum )
			MaxSum = ThisSum;
		else if( ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
