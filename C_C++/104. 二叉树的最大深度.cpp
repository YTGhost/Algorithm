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
    int maxDepth(TreeNode* root) {
        int res = 0;
        function<void(TreeNode* root, int depth)> dfs = [&](TreeNode* root, int depth) {
            if(!root) return;
            depth++;
            res = max(res, depth);
            dfs(root->left, depth);
            dfs(root->right, depth);
        };
        dfs(root, 0);
        return res;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

class Solution {
public:
    int dfs(TreeNode* root){
        if(!root->left && !root->right) return 1;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }

    int maxDepth(TreeNode* root) {
        int res = 0;
        if(root) res = dfs(root);
        return res;
    }
};