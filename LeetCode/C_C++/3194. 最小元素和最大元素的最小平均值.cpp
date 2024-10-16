class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i < n / 2; i++) {
            res = min(res, nums[i] + nums[n - 1 - i]);
        }
        return res / 2.0;
    }
};