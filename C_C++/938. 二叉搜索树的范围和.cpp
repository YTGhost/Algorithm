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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root)
        {
            if(L <= root->val && root->val <=R)
            {
                sum += root->val;
            }
            if(root->val > L)
            {
                rangeSumBST(root->left, L, R);
            }
            if(root->val < R)
            {
                rangeSumBST(root->right, L, R);
            }
        }
        return sum;
    }
};