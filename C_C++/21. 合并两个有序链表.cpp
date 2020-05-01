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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;
        while(l1 && l2)
        {
            if(l1->val <= l2->val){
                head->next = new ListNode(l1->val);
                l1 = l1->next;
                head = head->next;
                
            }else{
                head->next = new ListNode(l2->val);
                l2 = l2->next;
                head = head->next;
            }
        }
        while(l1)
        {
            head->next = new ListNode(l1->val);
            l1 = l1->next;
            head = head->next;
        }
        while(l2)
        {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
            head = head->next;
        }
        return dummyHead->next;
    }
};