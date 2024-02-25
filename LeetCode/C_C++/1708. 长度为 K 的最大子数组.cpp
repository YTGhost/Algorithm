class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int t = 0;
        int idx = 0;
        for(int i = n - k; i >= 0; i--) {
            if(nums[i] > t) {
                t = nums[i];
                idx = i;
            }
        }
        return vector<int>(nums.begin() + idx, nums.begin() + idx + k);
    }
};