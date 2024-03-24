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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        auto dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *lastSorted = head;
        ListNode *cur = head->next;
        while(cur) {
            if (cur->val >= lastSorted->val) {
                lastSorted = lastSorted->next;
            } else {
                auto prev = dummyNode;
                while(prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummyNode->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        while(head->next)
        {
            ListNode* t = head->next;
            ListNode* next = head->next->next;
            if(t->val < head->val) {
                ListNode* pre = dummyNode;
                ListNode* cur = dummyNode->next;
                while(cur != t) {
                    if(t->val <= cur->val) {
                        t->next = pre->next;
                        pre->next = t;
                        break;
                    }
                    pre = cur;
                    cur = cur ->next;
                }
                head->next = next;
            } else {
                head = head->next;
            }
        }
        return dummyNode->next;
    }
};