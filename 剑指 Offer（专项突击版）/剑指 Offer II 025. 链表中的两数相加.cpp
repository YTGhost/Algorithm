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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, res;
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() && !s2.empty()) {
            int a = s1.top();
            int b = s2.top();
            int sum = a + b + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            res.push(sum % 10);
        }
        while(!s1.empty()) {
            int a = s1.top();
            int sum = a + carry;
            s1.pop();
            carry = sum / 10;
            res.push(sum % 10);
        }
        while(!s2.empty()) {
            int a = s2.top();
            int sum = a + carry;
            s2.pop();
            carry = sum / 10;
            res.push(sum % 10);
        }
        if(carry) res.push(carry);
        while(!res.empty()) {
            int a = res.top();
            res.pop();
            head->next = new ListNode(a);
            head = head->next;
        }
        return dummy->next;
    }
};