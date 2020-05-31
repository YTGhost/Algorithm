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
    bool isS(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }
        if(left == NULL || right == NULL){
            return false;
        }
        if(left->val == right->val && isS(left->left, right->right) && isS(left->right, right->left)){
            return true;
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isS(root->left, root->right);
    }
};

// 5月31打卡重做
class Solution {
public:
    bool check(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val == right->val && check(left->left, right->right) && check(left->right, right->left)) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }
};