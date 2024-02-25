/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root1, TreeNode* root2, bool isOdd) {
        if(!root1) return;
        if(isOdd) {
            swap(root1->val, root2->val);
        }

        dfs(root1->left, root2->right, !isOdd);
        dfs(root1->right, root2->left, !isOdd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
};

class Solution {
public:
    void dfs(TreeNode* left, TreeNode* right, bool flag) {
        if(!left) return;
        dfs(left->left, right->right, !flag);
        dfs(left->right, right->left, !flag);
        if(flag) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }
};