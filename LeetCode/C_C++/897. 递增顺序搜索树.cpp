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
    TreeNode* res;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        res->right = root;
        root->left = NULL;
        res = res->right;
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(-1);
        res = dummyNode;
        dfs(root);
        return dummyNode->right;
    }
};