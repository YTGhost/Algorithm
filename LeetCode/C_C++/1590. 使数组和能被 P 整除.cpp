class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if(total % p == 0) return 0;
        vector<long long> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
…        return res == n ? -1 : res;
    }
};