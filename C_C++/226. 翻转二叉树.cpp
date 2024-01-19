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
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode* root)> dfs = [&](TreeNode* root) {
            if(!root) return;
            swap(root->left, root->right);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root || !root->left && !root->right) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode* t = root->left;
            root->left = root->right;
            root->right = t;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};