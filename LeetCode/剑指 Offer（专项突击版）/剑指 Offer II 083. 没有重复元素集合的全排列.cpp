class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int st[10];
    void dfs(vector<int>& nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(st[i]) continue;
            st[i] = 1;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            st[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
};