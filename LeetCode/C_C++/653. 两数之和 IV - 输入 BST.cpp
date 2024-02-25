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
    unordered_set<int> hash;
    int target;
    bool res = false;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(hash.count(target - root->val)) {
            res = true;
        }
        hash.insert(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        target = k;
        dfs(root);
        return res;
    }
};