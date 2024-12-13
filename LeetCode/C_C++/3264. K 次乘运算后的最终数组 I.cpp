class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            int minVal = INT_MAX;
            int idx = -1;
            for (int j = 0; j < n; j++) {
                if (nums[j] < minVal) {
                    minVal = nums[j];
                    idx = j;
                }
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};