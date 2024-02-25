class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        vector<int> res;
        int n = nums.size(), cur = 0;
        while(cur <= sum) {
            cur += nums[n - 1];
            sum -= nums[n - 1];
            res.push_back(nums[n - 1]);
            n--;
        }
        return res;
    }
};