class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> st(nums.size(), false);
        path.resize(nums.size(), 0);
        dfs(0, nums, st);
        return ans;
    }

    void dfs(int u, vector<int>& nums, vector<bool>& st){
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!st[i])
            {
                path[u] = nums[i];
                st[i] = true;
                dfs(u+1, nums, st);
                st[i] = false;
            }
        }
    }
};