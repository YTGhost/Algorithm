class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        vector<bool> visit(n, false);
        function<void(int)> dfs = [&](int cnt) {
            if(cnt == n) {
                res.push_back(path);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(visit[i]) continue;
                path.push_back(nums[i]);
                visit[i] = true;
                dfs(cnt + 1);
                path.pop_back();
                visit[i] = false;
            }
        };
        dfs(0);
        return res;
    }
};

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