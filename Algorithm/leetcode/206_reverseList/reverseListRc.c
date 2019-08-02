struct ListNode* reverseList(struct ListNode* head){
    if( !head || !head->next )
        return head;
    else{
        struct ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
}
