/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool flag = true;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            deque<int> deq;
            int n = q.size();
            while(n--) {
                auto item = q.front();
                q.pop();
                if(flag) deq.push_back(item->val);
                else deq.push_front(item->val);
                if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);
            }
            res.emplace_back(vector<int>(deq.begin(), deq.end()));
            flag = !flag;
        }
        return res;
    }
};