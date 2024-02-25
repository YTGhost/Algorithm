class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums) sum += abs(num);
        if(target > sum) return 0;
        vector<vector<int>> f(n + 1, vector<int>(2 * sum + 1));
        f[0][0 + sum] = 1;
        for(int i = 1; i <= n; i++) {
            int t = nums[i-1];
            for(int j = -sum; j <= sum; j++) {
                if(j - t + sum >= 0) f[i][j + sum] += f[i - 1][j + sum - t];
                if(j + t + sum <= 2 * sum) f[i][j + sum] += f[i - 1][j + sum + t];
            }
        }
        return f[n][sum + target];
    }
};