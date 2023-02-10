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
    int res;
    void dfs(TreeNode* root, bool flag) {
        if(!root) return;
        if(flag) {
            if(root->left) res += root->left->val;
            if(root->right) res += root->right->val;
        }
        bool isEven = root->val % 2 == 0;
        dfs(root->left, isEven);
        dfs(root->right, isEven);
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, false);
        return res;
    }
};