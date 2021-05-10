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
    void dfs(TreeNode* root, string& str) {
        if(!root) return;
        dfs(root->left, str);
        if(!root->left && !root->right) str += root->val;
        dfs(root->right, str);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1 = "";
        string str2 = "";
        dfs(root1, str1);
        dfs(root2, str2);
        return str1 == str2;
    }
};