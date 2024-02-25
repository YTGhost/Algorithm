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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            int temp;
            for(int i = 0; i < s; i++) {
                auto item = q.front();
                q.pop();
                if(level % 2 == 0) {
                    if(item->val % 2 == 0) return false;
                } else {
                    if(item->val % 2 == 1) return false;
                }
                if(i == 0) {
                    temp = item->val;
                } else {
                    if(level % 2 == 0) {
                        if(item->val <= temp) return false;
                    } else {
                        if(item->val >= temp) return false;
                    }
                    temp = item->val;
                }
                if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);
            }
            level++;
        }
        return true;
    }
};