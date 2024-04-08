class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        sort(nums.begin(), nums.end());
        int idx = n / 2;
        res += abs(nums[idx] - k);
        nums[idx] = k;
        for(int i = idx - 1; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) break;
            res += abs(nums[i + 1] - nums[i]);
            nums[i] = nums[i + 1];
        }
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] >= nums[i - 1]) break;
            res += abs(nums[i] - nums[i - 1]);
            nums[i] = nums[i - 1];
        }
        return res;
    }
};