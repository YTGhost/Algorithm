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
    int res = 0;
    bool dfs(TreeNode* root) {
        if(!root) return true;
        bool left = true, right = true;
        if(root->left) left = dfs(root->left) && root->left->val == root->val;
        if(root->right) right = dfs(root->right) && root->right->val == root->val;
        if(left && right) res++;
        return left && right;
    }
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};