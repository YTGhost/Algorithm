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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto item = q.front();
                q.pop();
                if(i == 0) res = item->val;
                if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);
            }
        }
        return res;
    }
};