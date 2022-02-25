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
    TreeNode* res;
    bool flag = false;
    void dfs(TreeNode* root, TreeNode* p) {
        if(!root) return;
        dfs(root->left, p);
        if(root == p) flag = true;
        else if(flag) {
            res = root;
            flag = false;
        }
        dfs(root->right, p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return res;
    }
};