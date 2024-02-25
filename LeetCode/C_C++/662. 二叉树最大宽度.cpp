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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while(q.size()) {
            vector<unsigned long long> nodes;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front().first;
                auto index = q.front().second;
                if(node->left) {
                    q.push({node->left, 2 * index});
                    nodes.push_back(2 * index);
                }
                if(node->right) {
                    q.push({node->right, 2 * index + 1});
                    nodes.push_back(2 * index + 1);
                }
                q.pop();
            }
            if(nodes.size()) {
                res = max(res, nodes[nodes.size() - 1] - nodes[0] + 1);
                nodes.clear();
            }
        }
        return res;
    }
};