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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        function<int(TreeNode* root)> dfs = [&](TreeNode* root) {
            if(!root) return 0;
            int left = dfs(root->left);
            int right = dfs(root->right);
            res = max(res, left + right);
            return max(left, right) + 1;
        };
        dfs(root);
        return res;
    }
};
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