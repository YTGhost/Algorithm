/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head; 
        }
        ListNode* t = deleteDuplicates(head->next);
        if(head->val == t->val){
            head->next = head->next->next;
            delete t;
        }
        return head;
    }
};