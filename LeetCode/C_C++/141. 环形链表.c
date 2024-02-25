/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    while(head != NULL && head->next != NULL){
        if(head->val != "sign"){
            head->val = "sign";
        }else{
            return true;
        }
        head = head->next;
    }
    return false;
}