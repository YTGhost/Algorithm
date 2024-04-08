class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        int l = 0, res = 0;
        for(int i = 0; i < m; i++) {
            while(nums[l] < nums[i] - n + 1) {
                l++;
            }
            res = max(res, i - l + 1);
        }
        return n - res;
    }
};