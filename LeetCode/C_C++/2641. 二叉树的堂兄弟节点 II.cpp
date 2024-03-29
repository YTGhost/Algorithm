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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> q = {root};
        root->val = 0;
        while(!q.empty()) {
            vector<TreeNode*> q2;
            int sum = 0;
            for(auto node : q) {
                if(node->left) {
                    q2.push_back(node->left);
                    sum += node->left->val;
                }
                if(node->right) {
                    q2.push_back(node->right);
                    sum += node->right->val;
                }
            }
            for(auto fa : q) {
                int t = (fa->left ? fa->left->val : 0) + (fa->right ? fa->right->val : 0);
                if(fa->left) {
                    fa->left->val = sum - t;
                }
                if(fa->right) {
                    fa->right->val = sum - t;
                }
            }
            q = move(q2);
        }
        return root;
    }
};