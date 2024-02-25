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
    bool ans = true;
    int height(TreeNode* root) {
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;    
    }
    bool difference(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(abs(height(left) - height(right)) <= 1 && (!left || !right)){
            return true;
        }
        if(abs(height(left) - height(right)) <= 1 && difference(left->left, left->right) && difference(right->left, right->right)){
            return true;
        }else{
            return false;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return difference(root->left, root->right);
    }
};