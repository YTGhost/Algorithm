class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        int res = 0;
        while(r < n) {
            if(nums[r] == 0) cnt++;
            while(cnt > 1) {
                if(nums[l] == 0) cnt--;
                l++;
            }
            res = max(res, r - l);
            r++;
        }
        return res;
    }
};