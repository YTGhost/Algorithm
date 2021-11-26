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
    TreeNode* res;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val > val) {
            searchBST(root->left, val);
        } else if(root->val < val) {
            searchBST(root->right, val);
        } else {
            res = root;
        }
        return res;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
        {
            if(val > root->val)
            {
                root = root->right;
            }else if(val < root->val)
            {
                root = root->left;
            }else
            {
                return root;
            }
        }
        return NULL;
    }
};