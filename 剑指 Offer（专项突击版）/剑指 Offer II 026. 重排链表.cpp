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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        } 
        return pre;
    }
    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode *p1, *p2;
        while(l1 && l2) {
            p1 = l1->next;
            p2 = l2->next;
            l1->next = l2;
            l1 = p1;
            l2->next = l1;
            l2 = p2;
        }
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = NULL;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};