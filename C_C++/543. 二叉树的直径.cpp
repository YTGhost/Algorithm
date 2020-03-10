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
    int maxLength = 0;
    int help(TreeNode* root){
        if(root == NULL)    return 0;
        int left = root->left ? help(root->left) + 1 : 0;
        int right = root->right ? help(root->right) + 1 : 0;
        maxLength = max(left + right, maxLength);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return maxLength;
    }
};