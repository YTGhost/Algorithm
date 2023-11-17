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
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto [nodeL, coinL] = dfs(root->left);
        auto [nodeR, coinR] = dfs(root->right);
        int nodes = nodeL + nodeR + 1;
        int coins = coinL + coinR + root->val;
        res += abs(coins - nodes);
        return {nodes, coins};
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};