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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int row, int col) {
            if(!root) return;
            m[col].push_back({row, root->val});
            dfs(root->left, row + 1, col - 1);
            dfs(root->right, row + 1, col + 1);
        };
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(auto& [_, t] : m) {
            ranges::sort(t);
            vector<int> vals;
            for(auto& [_, val]: t) {
                vals.push_back(val);
            }
            res.push_back(vals);
        }
        return res;
    }
};