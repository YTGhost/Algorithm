class Solution {
public:
    int cnts[105];
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            if(t - k >= 1) res += cnts[t - k];
            if(t + k <= 100) res += cnts[t + k];
            cnts[t]++;
        }
        return res;
    }
};