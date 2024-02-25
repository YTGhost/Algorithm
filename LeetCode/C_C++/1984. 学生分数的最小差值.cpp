class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int res = nums[0] - nums[k - 1], n = nums.size();
        for(int i = 1; i <= n - k; i++) {
            res = min(res, nums[i] - nums[k + i - 1]);
        }
        return res;
    }
};