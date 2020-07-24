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
    ListNode* deleteNode(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(head)
        {
            if(head->val == val){
                p->next = head->next;
                break;
            }
            else{
                p = p->next;
                head = head->next;
            }
        }
        return dummy->next;
    }
};