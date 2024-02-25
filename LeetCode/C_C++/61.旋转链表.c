/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* t = head;
    int N = 1;
    if(head == NULL){
        return NULL;
    }
    while(t->next != NULL){
        t = t->next;
        N++;
    }
    t->next = head;
    int i;
    t = head;
    for(i = 0;i<N-k%N;i++){
        t = t->next;
    }
    head = t;
    for(i = 0;i<N-1;i++){
        t = t->next;
    }
    t->next = NULL;
    return head;
}