class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for(int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                res += maxVal - minVal;
            }
        }
        return res;
    }
};