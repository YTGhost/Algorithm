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
    vector<int> a;
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return isValidBST(root->left) && judge(root) && isValidBST(root->right);
    }
    bool judge(TreeNode* root){
        if(a.empty()){
            a.push_back(root->val);
        }else{
            if(root->val <= a.back()){
                return false;
            }
            a.push_back(root->val);
        }
        return true;
    }
};