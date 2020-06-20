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
    int maxLength = INT_MIN;
    int getMax(TreeNode* root){
        if(!root) return 0;
        int left = max(0, getMax(root->left));
        int right = max(0, getMax(root->right));
        maxLength = max(maxLength, root->val + left + right);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        getMax(root);
        return maxLength;
    }
};