class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int n;
    void dfs(vector<int>& nums, int index) {
        res.push_back(path);
        for(int i = index; i < n; i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return res;
    }
};