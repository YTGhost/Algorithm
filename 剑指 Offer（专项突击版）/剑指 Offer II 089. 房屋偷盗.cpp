class Solution {
public:
    int f[105];
    int rob(vector<int>& nums) {
        int n = nums.size();
        f[1] = nums[0];
        for(int i = 2; i <= n; i++) {
            f[i] = max(f[i - 2] + nums[i - 1], f[i - 1]);
        }
        return f[n];
    }
};