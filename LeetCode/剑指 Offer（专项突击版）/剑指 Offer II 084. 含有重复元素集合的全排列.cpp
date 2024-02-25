class Solution {
public:
    vector<vector<int>> res;
    int st[10];
    vector<int> path;
    void dfs(vector<int>& nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(st[i] || i && nums[i] == nums[i - 1] && !st[i - 1]) {
                continue;
            }
            st[i] = 1;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            st[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }
};