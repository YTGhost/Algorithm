class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        if (nums[0] > 0) res++;
        int cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (cnt > nums[i] && cnt < nums[i + 1]) {
                res++;
            }
            cnt++;
        }
        if (cnt > nums[n - 1]) {
            res++;
        }
        return res;
    }
};