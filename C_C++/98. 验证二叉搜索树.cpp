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

class Solution {
public:
    vector<int> a;
    int sign;
    bool isValidBST(TreeNode* root) {
        travel(root);
        return sign != 0 ? false : true;
    }

    void travel(TreeNode* root){
        if(!root) return;
        travel(root->left);
        if(a.size() != 0 && root->val <= a[a.size() - 1]) sign = 1;
        a.push_back(root->val);
        travel(root->right);
    }
};