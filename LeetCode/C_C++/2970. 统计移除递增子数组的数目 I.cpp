class Solution {
public:
    bool check(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prev = -1;
        for(int i = 0; i < n; i++) {
            if(i >= l && i <= r) {
                continue;
            }
            if(prev == -1) {
                prev = nums[i];
                continue;
            }
            if(nums[i] > prev) {
                prev = nums[i];
            } else {
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(check(nums, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};