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
    bool isPart(TreeNode* A, TreeNode* B) {
        if(!B) return true;
        if(!A || A->val != B->val) return false;
        return isPart(A->left, B->left) && isPart(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        if(isPart(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};