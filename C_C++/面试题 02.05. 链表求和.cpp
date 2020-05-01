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
        int sum = 0, carry = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;

        while(l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            head->next = new ListNode((num1 + num2 + carry) % 10);
            carry = (num1 + num2 + carry) / 10;
            head = head->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry) head->next = new ListNode(carry);
        return dummyHead->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;

        while(l1 && l2)
        {
            head->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            head->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            head = head->next;
            l1 = l1->next;
        }
        while(l2)
        {
            head->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            head = head->next;
            l2 = l2->next;
        }
        if(carry) head->next = new ListNode(carry);
        return dummyHead->next;
    }
};