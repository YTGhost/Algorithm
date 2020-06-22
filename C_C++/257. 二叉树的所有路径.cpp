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
    vector<string> ans;
    void dfs(TreeNode* root, string str){
        if(!root) return;
        str += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(str);
            return;
        }
        str += "->";
        dfs(root->left, str);
        dfs(root->right, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};