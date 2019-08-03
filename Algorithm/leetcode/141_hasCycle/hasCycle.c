bool hasCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    if(!head)
        return false;
    slow = head; /* 慢指针 */
    fast = head->next; /* 快指针 */
    while(fast && fast->next)
    {
        if( slow == fast )
            return true;
        slow = slow->next; /* 慢指针每次走一步 */
        fast = fast->next->next; /* 快指针一次走两步 */
    }
    return false;
}
