class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), t = diff / 2;
        vector<vector<int>> f(n + 1, vector<int>(t + 1));
        f[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= t; j++) {
                f[i][j] = f[i - 1][j];
                if(j >= nums[i - 1]) f[i][j] += f[i - 1][j - nums[i - 1]];
            }
        }
        return f[n][t];
    }
};