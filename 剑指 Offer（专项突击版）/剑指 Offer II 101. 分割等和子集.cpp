class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxNum = 0;
        for(auto num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        if(maxNum > target) return false;
        vector<vector<int>> f(n, vector<int>(target + 1, 0));
        for(int i = 0; i < n; i++) {
            f[i][0] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                f[i][j] = f[i - 1][j];
                if(j >= nums[i]) f[i][j] |= f[i - 1][j - nums[i]];
            }
        }
        return f[n - 1][target];
    }
};