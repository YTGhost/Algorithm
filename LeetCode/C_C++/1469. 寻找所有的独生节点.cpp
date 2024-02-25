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
    vector<int> res;
    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left && !root->right) res.push_back(root->left->val);
        else if(!root->left && root->right) res.push_back(root->right->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return res;
    }
};