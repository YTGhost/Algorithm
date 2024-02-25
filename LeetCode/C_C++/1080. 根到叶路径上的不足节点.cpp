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
    TreeNode* dfs(TreeNode* root, int limit, int sum) {
        if(!root) return NULL;
        sum += root->val;
        if(!root->left && !root->right) {
            return sum < limit ? NULL : root;
        }
        root->left = dfs(root->left, limit, sum);
        root->right = dfs(root->right, limit, sum);
        return !root->left && !root->right ? NULL : root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit, 0);
    }
};