struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *uniq = head, *p = head;
    while(p)
    {
        if( p->val != uniq->val )
        {
            uniq->next = p;
            uniq = p;
        }
        p = p->next;
    }
    if(uniq)
        uniq->next = NULL;
    return head;
}
