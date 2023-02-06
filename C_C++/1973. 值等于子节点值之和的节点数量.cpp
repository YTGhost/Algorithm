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
    int res;
    long long dfs(TreeNode* root) {
        if(!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long sum = left + right;
        if(sum == root->val) res++;
        return left + right + root->val;
    }
    int equalToDescendants(TreeNode* root) {
        dfs(root);
        return res;
    }
};