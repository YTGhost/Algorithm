class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            if(mp.count(prefixSum[i + 1] - goal)) {
                res += mp[prefixSum[i + 1] - goal];
            }
            mp[prefixSum[i + 1]]++;
        }
        return res;
    }
};