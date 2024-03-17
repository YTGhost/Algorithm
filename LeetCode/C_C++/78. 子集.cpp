class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++) {
            path.clear();
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    path.push_back(nums[j]);
                }
            }
            res.push_back(path);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        vector<bool> visit(n, false);
        function<void(int)> dfs = [&](int idx) {
            res.push_back(path);
            for(int i = idx; i < n; i++) {
                path.push_back(nums[i]);
                visit[i] = true;
                dfs(i + 1);
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < 1 << n; i++)
        {
            vector<int> path;
            for(int j = 0; j < n; j++)
                if(i >> j & 1)
                    path.emplace_back(nums[j]);
            res.emplace_back(path);
        }
        return res;
    }
};