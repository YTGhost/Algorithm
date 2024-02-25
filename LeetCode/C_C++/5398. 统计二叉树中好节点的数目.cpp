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
    int judge(TreeNode* root, int maxNum){
        if(!root) return 0;
        int count = 0;
        maxNum = max(maxNum, root->val);
        count += judge(root->left, maxNum);
        count += judge(root->right, maxNum);
        if(root->val >= maxNum) count++;
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        int count;
        if(!root) return 0;
        else{
            count = 0;
            count += judge(root, root->val);
        }
        return count;
    }
};