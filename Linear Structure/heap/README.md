# 堆栈
## 堆栈的顺序存储实现
栈的顺序存储结构通常由一个一位数组和一个记录栈顶元素位置的变量组成。  

```c
#define MAXSIZE<存储数据元素的最大个数>
typedef struct *SNode Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top;
};
```
#### [堆栈函数Push、Pop](arraystack.c)
### 用一个数组实现两个堆栈
只要数组还存在空间就可以入栈，最大化利用数组空间。  
【分析】使两个栈分别从数组的两边开始向中间生长，当两个栈的栈顶指针相遇时，表示两个栈都满了。  
```c
#define MAXSIZE
struct DoubleStack
{
    ElementType Data[MAXSIZE];
    int Top1;
    int Top2;
}S;
S->Top1 = -1; //第一个栈顶
S->Top2 = MAXSIZE; //第二个栈顶
```
## 堆栈的链式存储实现
堆栈的链式结构实际上就是一个单链表，叫做链栈。插入和删除操作只能在链栈的栈顶进行。  
***栈顶指针应该指向链表的头***
```c
typedef struct lSNode *linkstack;
struct lSNode
{
    ELementType Data;
    linkstack Next;
};
```
#### [相关函数](./linkstack.c)
