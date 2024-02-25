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
    int t = 0;
    void dfs(ListNode* head) {
        if(!head->next->next) return;
        dfs(head->next);
        t = max(t, head->next->next->val);
        if(t > head->next->val) {
            head->next = head->next->next;
        }
    }
    ListNode* removeNodes(ListNode* head) {
        auto dummyNode = new ListNode(-1, head);
        auto p = dummyNode;
        dfs(p);
        return dummyNode->next;
    }
};