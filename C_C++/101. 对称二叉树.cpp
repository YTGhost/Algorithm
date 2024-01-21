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
    bool dfs(TreeNode* node1, TreeNode* node2) {
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        return node1->val == node2->val && dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
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