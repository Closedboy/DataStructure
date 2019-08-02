struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        struct ListNode* ntemp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = ntemp;
    }
    return pre;
}
