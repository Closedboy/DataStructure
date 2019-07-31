#ifndef _MERGETWOLISTS_H
#define _MERGETWOLISTS_H

typedef int ElementType;
typedef struct Node *List;
struct Node {
    ElementType Data;
    List Next;
};

List Merge( List L1, List L2 ); /* 迭代实现 */
List MergeRecursive( List L1, List L2 ); /* 递归实现 */

#endif