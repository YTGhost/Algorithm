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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        function<int(TreeNode*, long)> dfs = [&](TreeNode* root, long target) -> int {
            int res = 0;
            if(!root) return res;
            if(target == root->val) {
                res++;
            }
            res += dfs(root->left, target - root->val);
            res += dfs(root->right, target - root->val);
            return res;
        };
        int res = dfs(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }
};

class Solution {
public:
    int res, target;
    void dfs1(TreeNode* root) {
        if(!root) return;
        dfs2(root, root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root, int sum) {
        if(sum == target) res++;
        if(root->left) dfs2(root->left, sum + root->left->val);
        if(root->right) dfs2(root->right, sum + root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs1(root);
        return res;
    }
};