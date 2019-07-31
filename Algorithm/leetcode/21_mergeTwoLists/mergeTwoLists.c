#include <stdio.h>
#include <stdlib.h>
#include "mergeTwoLists.h"

List MergeRecursive( List L1, List L2 )
{
    if(!L1) return L2;
    else if(!L2) return L1;
    else if(L1->Data < L2->Data)
    {
        L1->Next = MergeRecursive(L1->Next, L2);
        return L1;
    }
    else
    {
        L2->Next = MergeRecursive(L2->Next, L1);
        return L2;
    }
}