class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        if(n < 3) {
            return 0;
        }
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = nums[0];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }
        maxRight[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }
        for(int i = 1; i < n - 1; i++) {
            res = max(res, (maxLeft[i - 1] - nums[i]) * (long long)maxRight[i + 1]);
        }
        
        return res;
    }
};