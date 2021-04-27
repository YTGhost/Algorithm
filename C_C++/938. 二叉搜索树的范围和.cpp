/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 2021/04/27 每日一题
class Solution {
public:
    int res;
    void inorder(TreeNode* root, int low, int high) {
        if(!root) return;
        inorder(root->left, low, high);
        if(root->val >= low && root->val <= high)
            res += root->val;
        inorder(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return res;
    }
};

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