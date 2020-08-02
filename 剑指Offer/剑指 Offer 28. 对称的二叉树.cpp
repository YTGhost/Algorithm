/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left || !right) return !left && !right;
        if(left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
};