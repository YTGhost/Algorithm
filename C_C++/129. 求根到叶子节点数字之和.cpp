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
    int res;
    void dfs(TreeNode* root, int sum) {
        if(!root) return;
        if(!root->left && !root->right) {
            sum = sum * 10 + root->val;
            res += sum;
            return;
        }
        sum = sum * 10 + root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};