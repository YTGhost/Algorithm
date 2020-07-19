/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// LeetCode究极班打卡
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto dummy = new ListNode(-1), cur = dummy;
        while(l1 || l2 || carry)
        {
            if(l1) carry += l1->val, l1 = l1->next;
            if(l2) carry += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(carry%10);
            carry /= 10;
        }
        return dummy->next;
    }
};