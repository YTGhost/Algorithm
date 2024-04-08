class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        for(int l = 0, r = 1; r < n; r++) {
            if(nums[r] <= nums[r - 1]) {
                l = r;
                continue;
            }
            res = max(res, r - l + 1);
        }
        for(int l = 0, r = 1; r < n; r++) {
            if(nums[r] >= nums[r - 1]) {
                l = r;
                continue;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};