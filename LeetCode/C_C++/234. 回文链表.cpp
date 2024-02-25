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
    ListNode* middleNode(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* pre = NULL;
        ListNode* cur = node;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* mid = middleNode(dummyNode);
        ListNode* temp = mid->next;
        mid->next = NULL;
        mid = reverse(temp);
        while(head && mid)
        {
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};