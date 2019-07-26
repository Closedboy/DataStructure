# 队列
具有一定操作约束的线性表，只能在一端插入，而在另一端删除。FIFO，先进先出。  
## ADT描述
数据对象集：一个有0个或多个元素的又穷线性表。
操作集：长度为MAXSIZE的队列Q，队列元素item
```c
Queue CreateQueue(int MAXSIZE) //生成长度为MAXSIZE的空队列
```
## 队列的顺序存储实现
队列的顺序存储结构通常由一个**一维数组**和一个记录队列头元素位置的变量**front**以及一个记录队尾元素位置的变量**rear**组成。
```c
#define MAXSIZE <储存数据元素的最大个数>
typedef struct{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
}QNode, *Queue;
```