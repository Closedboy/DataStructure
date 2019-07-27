# 队列
具有一定操作约束的线性表，只能在一端插入，而在另一端删除。FIFO，先进先出。  
## ADT描述
数据对象集：一个有0个或多个元素的又穷线性表。
操作集：长度为MAXSIZE的队列Q，队列元素item
```c
Queue CreateQueue(int MAXSIZE) //生成长度为MAXSIZE的空队列
```
## 队列的顺序存储实现
队列的顺序存储结构通常由一个***一维数组***和一个记录队列头元素位置的变量***front***以及一个记录队尾元素位置的变量***rear***组成。
```c
#define MAXSIZE <储存数据元素的最大个数>
typedef struct{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
}QNode, *Queue;
```
**循环队列**
- 队列的长度用front和rear的差值表明，共有n种差值情况；  
- 而队列所处的状态共有n+1种情况（空、有n个元素）；
- 解决方案：
    - 使用额外标记:Size(队列长度)或Tag(插入为1，删除为0)域
    - 仅使用n-1个数组空间
[顺序存储函数实现](./arrayqueue.c)
## 队列的链式存储实现
队列的链式存储结构也可以用一个单链表实现。插入和删除操作分别在链表的两头进行；队列指针front应该指向链表的头，rear指向链表的尾。
```c
typedef int ElementType;
typedef Node *List;
typedef QNode *linkqueue;
struct Node
{
    ElementType Data;
    List Next;
};
struct QNode
{
    List front;
    List rear; 
};
```
[链式存储函数实现](./linkqueue.c)
***注意front和rear的意义***
