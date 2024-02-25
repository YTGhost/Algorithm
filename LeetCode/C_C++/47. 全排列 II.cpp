class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& path, vector<bool>& st, int u) {
        if(u == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!st[i]) {
                if(i && nums[i-1] == nums[i] && !st[i-1]) continue;
                path[u] = nums[i];
                st[i] = true;
                dfs(nums, path, st, u+1);
                st[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path(nums.size());
        vector<bool> st(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, path, st, 0);
        return res;
    }
};