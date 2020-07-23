/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    vector<int> res;
    void dfs(ListNode* node){
        if(!node->next){
            res.push_back(node->val);
            return;
        }
        dfs(node->next);
        res.push_back(node->val);
    }
    
    vector<int> reversePrint(ListNode* head) {
        if(!head) return res;
        dfs(head);
        return res;
    }
};

// 遍历反转
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};