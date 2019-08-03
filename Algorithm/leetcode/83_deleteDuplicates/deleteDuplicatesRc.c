struct ListNode* deleteDuplicatesRc(struct ListNode* head){
    if( !head || !head->next)
        return head;
    else
    {
        head->next = deleteDuplicatesRc(head->next);
        if( head->val == head->next->val )
        {
            struct ListNode *temp = head;
            head = head->next;
            free(temp);
        }
        return head;
    }
}
