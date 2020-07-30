/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 普通遍历
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        for(auto t = head; t; t = t->next) n++;
        if(n < k) return NULL;
        auto t = head;
        for(int i = 0; i < n-k; i++) t = t->next;
        return t;
    }
};

// 快慢指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto fast = head, slow = head;
        while(fast && k)
        {
            fast = fast->next;
            k--;
        }
        // if(k) return NULL;   k大于链表长度，可以返回NULL
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};