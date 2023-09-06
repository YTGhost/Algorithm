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
    TreeNode* res;
    int maxDepth;
    int dfs(TreeNode* root, int depth) {
        if(!root) {
            maxDepth = max(maxDepth, depth);
            return depth;
        }
        int left = dfs(root->left, depth+1);
        int right = dfs(root->right, depth+1);
        if(left == right && right == maxDepth) {
            res = root;
        }
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};