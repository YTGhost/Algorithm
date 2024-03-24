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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *ptr = nullptr;
        int carry = 0;
        while(l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            if (!head) {
                head = new ListNode(sum % 10);
                ptr = head;
            } else {
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }
            carry = sum / 10;
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        if(carry) {
            ptr->next = new ListNode(carry);
        }
        return head;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyNode = new ListNode(0);
        ListNode* cur = dummyNode;
        while(carry || l1 || l2)
        {
            int l1Val = l1 ? l1->val : 0;
            int l2Val = l2 ? l2->val : 0;
            int val = l1Val + l2Val + carry;
            ListNode* temp = new ListNode(val % 10);
            cur->next = temp;
            cur = cur->next;
            carry = val / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummyNode->next;
    }
};
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