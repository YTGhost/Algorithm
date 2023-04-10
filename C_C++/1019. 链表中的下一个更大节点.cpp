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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int, int>> stk;
        ListNode* cur = head;
        int idx = -1;
        while(cur) {
            idx++;
            res.push_back(0);
            while(!stk.empty() && stk.top().first < cur->val) {
                res[stk.top().second] = cur->val;
                stk.pop();
            }
            stk.push({cur->val, idx});
            cur = cur->next;
        }
        return res;
    }
};