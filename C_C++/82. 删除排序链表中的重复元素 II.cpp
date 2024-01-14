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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        auto dummyNode = new ListNode(-1, head);
        auto p = dummyNode;
        while(p->next && p->next->next) {
            if(p->next->val == p->next->next->val) {
                int x = p->next->val;
                while(p->next && p->next->val == x) {
                    p->next = p->next->next;
                }
            } else {
                p = p->next;
            }
        }
        return dummyNode->next;

    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        while(pre->next)
        {
            ListNode* t = pre->next;
            while(t && pre->next->val == t->val) t = t->next;
            if(pre->next->next == t) pre = pre->next;
            else pre->next = t;
        }
        return dummyNode->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next)
        {
            auto q = p->next;
            while(q && p->next->val == q->val) q = q->next;
            if(p->next->next == q) p = p->next;
            else p->next = q;
        }
        return dummy->next;
    }
};