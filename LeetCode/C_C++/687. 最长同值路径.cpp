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
    int res;
    pair<int, int> dfs(TreeNode* root) {
        if(!root->left && !root->right) {
            return { root->val, 0 };
        }
        int totalLen = 0;
        int node1 = -1001, len1 = 0, node2 = -1001, len2 = 0;
        if(root->left) {
            tie(node1, len1) = dfs(root->left);
            if(node1 == root->val) {
                totalLen += len1 + 1;
            }
        }
        if(root->right) {
            tie(node2, len2) = dfs(root->right);
            if(node2 == root->val) {
                totalLen += len2 + 1;
            }
        }
        res = max(res, totalLen);
        if(root->val != node1 && root->val != node2) {
            return { root->val, 0 };
        } else if(root->val == node1 && root->val == node2) {
            return { root->val, max(len1, len2) + 1 };
        } else if(root->val == node1) {
            return { root->val, len1 + 1 };
        }
        return {root->val, len2 + 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root) dfs(root);
        return res;
    }
};