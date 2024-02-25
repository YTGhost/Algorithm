class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0, res = INT_MAX;
        while(r < n) {
            sum += nums[r];
            while(l <= r && sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
};