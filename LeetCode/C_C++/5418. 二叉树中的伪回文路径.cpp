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
    int count;
    
    int check(int state){
        if(state == 0 || state == 1 || state == 2 || state == 4 || state == 8 || state == 16 || state == 32 || state == 64 || state == 128 || state == 256) return true;
        return false;
    }
    
    void dfs(TreeNode* root, int state){
        if(!root->left && !root->right){
            state ^= 1 << (root->val - 1);
            if(check(state)) count++;
            return;
        }
        state ^= 1 << (root->val - 1);
        if(root->left) dfs(root->left, state);
        if(root->right) dfs(root->right, state);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int state = 0;
        dfs(root, state);
        return count;
    }
};