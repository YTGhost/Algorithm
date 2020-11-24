/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 二分TODO


// 暴力递归
class Solution {
public:
    int sum;
    int countNodes(TreeNode* root) {
        if(!root) return sum;
        countNodes(root->left);
        sum += 1;
        countNodes(root->right);
        return sum;
    }
};