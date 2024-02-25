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
    vector<vector<int>> res;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int height = max(left, right);
        if(height == res.size()) {
            res.push_back(vector<int>{});
        }
        res[height].push_back(root->val);
        return height + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};