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
    void dfs(TreeNode* root, int rootVal) {
        if(!root) return;
        if(root->val >= rootVal) {
            res++;
            rootVal = root->val;
        }
        dfs(root->left, rootVal);
        dfs(root->right, rootVal);
    }
    int goodNodes(TreeNode* root) {
        int rootVal = INT_MIN;
        dfs(root, rootVal);
        return res;
    }
};