 ListNode *reverseList(ListNode *head) {
     
      if(head==NULL)
        return NULL;

    ListNode *pointer = head->next;
    head->next = NULL;
    
    while(pointer!=NULL){
        
        ListNode *p = pointer->next;
        
        pointer->next = head;
        head = pointer;
        pointer = p;
        
        
    }
    return head;
    }