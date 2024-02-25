class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return prefixSum;
    }
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum = getPrefixSum(nums);
        long long res = LONG_MIN;
        unordered_map<int, int> m;
        for(int j = 0; j < n; j++) {
            if(m.count(nums[j] + k)) {
                res = max(res, prefixSum[j + 1] - prefixSum[m[nums[j] + k]]);
            }
            if(m.count(nums[j] - k)) {
                res = max(res, prefixSum[j + 1] - prefixSum[m[nums[j] - k]]);
            }
            if(m.count(nums[j])) {
                if(prefixSum[j] - prefixSum[m[nums[j]]] < 0) {
                    m[nums[j]] = j;
                }
            } else {
                m[nums[j]] = j;
            }
        }
        return res == LONG_MIN ? 0 : res;
    }
};