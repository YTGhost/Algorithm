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
    int maxCnt = 0;
    unordered_map<int, int> m;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        m[sum]++;
        maxCnt = max(maxCnt, m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        dfs(root);
        for(auto item : m) {
            if(item.second == maxCnt) {
                res.push_back(item.first);
            }
        }
        return res;
    }
};