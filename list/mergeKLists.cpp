class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if(l1==NULL && l2==NULL)
        return NULL;
        // 头指针
        ListNode *l = new ListNode(0);
        l->next = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *tail = l;
        
        while(p1!=NULL && p2!=NULL){
            if(p1->val <= p2->val){
                tail->next = p1;
                tail = p1;
                p1 = p1->next;
            }
            else{
                tail->next = p2;
                tail = p2;
                p2 = p2->next;
            }
        }
        tail->next = p1?p1:p2;
        return l->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL; 
        ListNode *header = new ListNode(0);
        header->next = lists[0];
        for(int i = 1; i<lists.size(); i++){
            header->next = mergeTwoLists(header->next, lists[i]);
        }
        return header->next;
    }
};