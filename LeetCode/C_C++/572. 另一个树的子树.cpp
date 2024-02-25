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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return isSubtree(s->left, t) || judge(s, t) || isSubtree(s->right, t);
    }

    bool judge(TreeNode* s, TreeNode* t){
        if((!s && t) || (s && !t)) return false;
        if(!s && !t) return true;
        return judge(s->left, t->left) && s->val == t->val && judge(s->right, t->right);
    }
};