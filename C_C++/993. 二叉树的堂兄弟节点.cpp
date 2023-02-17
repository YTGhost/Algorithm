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
    int deepX, deepY, fatherX, fatherY;
    void dfs(TreeNode* root, int x, int y, int deep) {
        if(!root) return;
        if(root->left) {
            if(root->left->val == x) {
                deepX = deep + 1;
                fatherX = root->val;
            }
            if(root->left->val == y) {
                deepY = deep + 1;
                fatherY = root->val;
            }
        }
        if(root->right) {
            if(root->right->val == x) {
                deepX = deep + 1;
                fatherX = root->val;
            }
            if(root->right->val == y) {
                deepY = deep + 1;
                fatherY = root->val;
            }
        }
        dfs(root->left, x, y, deep + 1);
        dfs(root->right, x, y, deep + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0);
        return deepX == deepY && fatherX != fatherY;
    }
};