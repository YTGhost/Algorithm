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
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};