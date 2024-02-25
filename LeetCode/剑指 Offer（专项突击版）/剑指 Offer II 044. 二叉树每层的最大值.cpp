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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int val = INT_MIN;
            for(int i = 0; i < n; i++) {
                auto item = q.front();
                q.pop();
                val = max(val, item->val);
                if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);
            }
            res.push_back(val);
        }
        return res;
    }
};