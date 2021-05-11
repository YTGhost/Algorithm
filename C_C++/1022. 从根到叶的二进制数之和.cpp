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
    void dfs(TreeNode* root, int sum) {
        if(!root) return;
        sum <<= 1;
        sum += root->val;
        if(!root->left && !root->right) {
            res += sum;
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};