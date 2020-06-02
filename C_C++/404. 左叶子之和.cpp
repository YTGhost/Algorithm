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
    int sum;
    void toCompute(TreeNode* root){
        if(!root) return;
        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        toCompute(root->left);
        toCompute(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        toCompute(root);
        return sum;
    }
};