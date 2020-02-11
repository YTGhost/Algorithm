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