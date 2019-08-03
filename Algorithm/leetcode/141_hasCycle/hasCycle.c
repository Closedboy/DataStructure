bool hasCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    if(!head)
        return false;
    slow = head;
    fast = head->next;
    while(fast && fast->next)
    {
        if( slow == fast )
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
