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
    pair<vector<int>, int> dfs(TreeNode* root, int distance) {
        vector<int> depths(distance + 1);
        if(!root) {
            return { depths, 0 };
        }
        if(!root->left && !root->right) {
            depths[0] = 1;
            return { depths, 0 };
        }

        auto [depthsLeft, pairLeft] = dfs(root->left, distance);
        auto [depthsRight, pairRight] = dfs(root->right, distance);

        for(int i = 0; i < distance; i++) {
            depths[i + 1] += depthsLeft[i];
            depths[i + 1] += depthsRight[i];
        }

        int cnt = 0;
        for(int i = 0; i <= distance - 2; i++) {
            for(int j = 0; i + j + 2 <= distance; j++) {
                cnt += depthsLeft[i] * depthsRight[j];
            }
        }

        return { depths, cnt + pairLeft + pairRight };
    }
    int countPairs(TreeNode* root, int distance) {
        auto [_, res] = dfs(root, distance);
        return res;
    }
};