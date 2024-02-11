class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int res = 0;
        function<bool(int)> check = [&](int idx) {
            for(int k = 0; k < m; k++) {
                if(pattern[k] == 1 && nums[idx + k + 1] <= nums[idx + k]) {
                    return false;
                }
                if(pattern[k] == 0 && nums[idx + k + 1] != nums[idx + k]) {
                    return false;
                }
                if(pattern[k] == - 1 && nums[idx + k + 1] >= nums[idx + k]) {
                    return false;
                }
            }
            return true;
        };
        for(int i = 0; i < n - m; i++) {
            if(check(i)) {
                res++;
            }
        }
        return res;
    }
};