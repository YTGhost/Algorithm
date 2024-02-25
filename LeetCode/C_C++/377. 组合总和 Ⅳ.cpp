// 2021/04/24 每日一题

// 二维
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<unsigned long long>> f(target+1, vector<unsigned long long>(target+1));
        f[0][0] = 1;
        int res = 0;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                for(auto num : nums)
                {
                    if(j >= num) f[i][j] += f[i-1][j-num];
                }
            }
            res += f[i][target];
        }
        return res;
    }
};
// 一维
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> f(target+1);
        f[0] = 1;
        int res = 0;
        for(int j = 0; j <= target; j++)
            for(auto num : nums)
                if(j >= num) f[j] += f[j-num];
        res += f[target];
        return res;
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> f(target+1, 0);
        f[0] = 1;
        for(int i = 1; i <= target; i++)
            for(auto num : nums)
                if(i >= num) f[i] += f[i-num];
        return f[target];
    }
};