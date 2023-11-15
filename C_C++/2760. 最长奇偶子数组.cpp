class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, n = nums.size();
        int l = 0, r = 0;
        while(l < n && r < n) {
            while(l < n && (nums[l] % 2 != 0 || nums[l] > threshold)) {
                l++;
            }
            r = l;
            while(r < n - 1 && nums[r + 1] % 2 != nums[r] % 2 && nums[r + 1] <= threshold) {
                r++;
            }
            if(l >= n || r >= n) break;
            res = max(res, r - l + 1);
            l++;
            r = l;
        }
        return res;
    }
};