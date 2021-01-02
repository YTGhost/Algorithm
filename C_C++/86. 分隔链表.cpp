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
    ListNode* partition(ListNode* head, int x) {
        auto dummyNode1 = new ListNode(-1);
        auto dummyNode2 = new ListNode(-1);
        auto t1 = dummyNode1;
        auto t2 = dummyNode2;
        while(head) {
            if(head->val < x) {
                t1->next = new ListNode(head->val);
                t1 = t1->next;
            } else {
                t2->next = new ListNode(head->val);
                t2 = t2->next;
            }
            head = head->next;
        }
        t1->next = dummyNode2->next;
        return dummyNode1->next;
    }
};