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
    void dfs(TreeNode* root, int val, int cur, int depth) {
        if(!root) return;
        dfs(root->left, val, cur + 1, depth);
        dfs(root->right, val, cur + 1, depth);
        if(cur == depth - 1) {
            TreeNode* newLeft = new TreeNode(val, root->left, NULL);
            TreeNode* newRight = new TreeNode(val, NULL, root->right);
            root->left = newLeft;
            root->right = newRight;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        dfs(root, val, 1, depth);
        return root;
    }
};