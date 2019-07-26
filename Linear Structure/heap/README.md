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
