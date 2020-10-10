/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 哈希表，空间复杂度O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head)
        {
            if(set.count(head)) return head;
            set.insert(head);
            head = head->next;
        }
        return head;
    }
};