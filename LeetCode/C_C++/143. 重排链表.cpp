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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    void merge(ListNode* l1, ListNode* l2) {
        ListNode* ll1;
        ListNode* ll2;
        while(l1 && l2)
        {
            ll1 = l1->next;
            ll2 = l2->next;
            l1->next = l2;
            l1 = ll1;
            l2->next = l1;
            l2 = ll2;
        }
    }

    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* middle = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = middle->next;
        middle->next = NULL;
        l2 = reverseList(l2);
        merge(l1, l2);
    }
};