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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        ListNode* t = head;
        int n = 0;
        while(t->next) {
            n++;
            t = t->next;
        }
        ListNode* tail = t;
        n++;
        k %= n;
        if(!k) return head;
        t = head;
        for(int i = 0; i < n-k-1; i++) t = t->next;
        ListNode* res = t->next;
        t->next = NULL;
        tail->next = head;
        return res;
    }
};