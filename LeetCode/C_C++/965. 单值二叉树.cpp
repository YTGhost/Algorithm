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
    bool isUnivalTree(TreeNode* root) {
        if(!root){
            return true;
        }
        int init = root->val;
        queue<TreeNode*> a;
        a.push(root);
        while(!a.empty())
        {
            int lenth = a.size();
            for(int i = 0; i < lenth; i++)
            {
                TreeNode* temp = a.front();
                if(temp->val != init)
                {
                    return false;
                }
                if(temp->left)
                {
                    a.push(temp->left);
                }
                if(temp->right)
                {
                    a.push(temp->right);
                }
                a.pop();
            }
        }
        return true;
    }
};