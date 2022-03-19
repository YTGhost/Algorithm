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
    string res = "";
    void dfs(TreeNode* root, bool flag) {
        if(!root) {
            if(flag) res += "()";
            return;
        }
        res += '(';
        res += to_string(root->val);
        dfs(root->left, root->right ? true : false);
        dfs(root->right, false);
        res += ')';
    }
    string tree2str(TreeNode* root) {
        dfs(root, false);
        return res.substr(1, res.length() - 2);
    }
};