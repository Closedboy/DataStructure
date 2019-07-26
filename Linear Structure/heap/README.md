# 堆栈
## 栈的顺序存储实现
栈的顺序存储结构通常由一个一位数组和一个记录栈顶元素位置的变量组成。  

```c
#define MAXSIZE<存储数据元素的最大个数>
typedef struct *SNode Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int Top;
};
```
### 堆栈函数Push、Pop的实现
```c
void Push(arraystack S, ELementType item)
{
    if( S->Top == MAXSIZE - 1)
    {
        printf("Stack is full!\n");
        return;
    }
    else
    {
        S->Data[++(S->Top)] = item;
        return;
    }
    
}

ELementType Pop(arraystack S)
{
    if( S->Top == -1 )
    {
        printf("Stack is empty!\n");
        return ERROR;
    }
    else
        return S->Data[(S->Top)--];
}
```
