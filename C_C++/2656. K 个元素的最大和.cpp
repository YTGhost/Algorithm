class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxValue = 0;
        for(auto num : nums) {
            maxValue = max(maxValue, num);
        }
        return k * maxValue + (k - 1) * k / 2;
    }
};