/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head; 
    }
    struct ListNode* t = deleteDuplicates(head->next);
    if(head->val == t->val){
        head->next = head->next->next;
        free(t);
    }
    return head;
}