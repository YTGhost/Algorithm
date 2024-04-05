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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int maxVal, int minVal){
            if(!root) return;
            res = max({res, abs(maxVal - root->val), abs(minVal - root->val)});
            maxVal = max(maxVal, root->val);
            minVal = min(minVal, root->val);
            dfs(root->left, maxVal, minVal);
            dfs(root->right, maxVal, minVal);
        };
        dfs(root, root->val, root->val);
        return res;
    }
};