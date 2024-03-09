/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
            if(l > r) return NULL;
            int mid = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = dfs(l, mid - 1);
            root->right = dfs(mid + 1, r);
            return root;
        };
        return dfs(0, nums.size() - 1);
    }
};

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid-1);
        root->right = dfs(nums, mid+1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};