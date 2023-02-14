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
    int res, count;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int cur = count;
        count++;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        int average = sum / (count - cur);
        if(root->val == average) res++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};