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
    void flatten(TreeNode* root) {
        while(root) {
            auto node = root->left;
            while(node && node->right) {
                node = node->right;
            }
            if(node) {
                node->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root)
        {
            auto p = root->left;
            if(p){
                while(p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};