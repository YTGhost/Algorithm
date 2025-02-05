class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int idx) {
            if (idx == n) {
                res.push_back(path);
                return;
            }
            path.push_back(nums[idx]);
            dfs(idx + 1);
            path.pop_back();
            idx++;
            while (idx < n && nums[idx] == nums[idx - 1]) {
                idx++;
            }
            dfs(idx);
        };
        dfs(0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++)
        {
            temp.clear();
            bool flag = true;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j)) {
                    if(j && (i >> (j-1) & 1) == 0 && nums[j] == nums[j-1]) {
                        flag = false;
                        break;
                    }
                    temp.emplace_back(nums[j]);
                }
            }
            if(flag) res.emplace_back(temp);
        }
        return res;
    }
};