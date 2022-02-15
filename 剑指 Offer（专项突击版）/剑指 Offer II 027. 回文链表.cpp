/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *slow = head, *fast = head, *pre = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            auto next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        if(fast) slow = slow->next;
        while(slow) {
            if(slow->val != pre->val) return false;
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }
};