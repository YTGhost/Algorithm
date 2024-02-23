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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        vector<int> nums;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        function<int(int target)> lower_bound = [&](int target) {
            int l = 0, r = nums.size();
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };
        int n = nums.size();
        for(auto query : queries) {
            int minI = lower_bound(query + 1) - 1, maxI = lower_bound(query);
            res.push_back({minI == -1 ? -1 : nums[minI], maxI == n ? -1 : nums[maxI]});
        }
        return res;
    }
};