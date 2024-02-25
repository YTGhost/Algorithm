class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j] && f[i - nums[j]] <= INT_MAX - f[i]) {
                    f[i] += f[i - nums[j]];
                }
            }
        }
        return f[target];
    }
};