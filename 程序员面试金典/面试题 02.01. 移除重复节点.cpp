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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* t = head;
        if(!t) return head;
        unordered_set<int> set;
        set.insert(t->val);
        while(t->next)
        {
            if(set.count(t->next->val)) t->next = t->next->next;
            else{
                set.insert(t->next->val);
                t = t->next;
            } 
        }
        return head;
    }
};