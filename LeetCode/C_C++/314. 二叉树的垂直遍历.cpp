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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<vector<int>> nodes(200);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 99});
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto item = q.front();
                q.pop();
                auto node = item.first;
                int level = item.second;
                nodes[level].push_back(node->val);
                if(node->left) q.push({node->left, level - 1});
                if(node->right) q.push({node->right, level + 1});
            }
        }
        for(int i = 0; i < 200; i++) {
            if(nodes[i].size()) {
                res.push_back(nodes[i]);
            }
        }
        return res;
    }
};