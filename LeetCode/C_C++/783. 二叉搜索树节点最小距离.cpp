/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 2021/04/13 每日一题
class Solution {
public:
    int pre = -1;
    int res = 100010;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(pre == -1) pre = root->val;
        else res = min(res, root->val - pre), pre = root->val;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};
class Solution {
public:
    int pre = -1;
    int res = INT_MAX;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(pre == -1) {
            pre = root->val;
        } else {
            res = min(res, root->val - pre);
            pre = root->val;
        }
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
    }
};