class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0;
        int t = -1;
        for(auto num : nums) {
            t &= num;
            if(t == 0) {
                res++;
                t = -1;
            }
        }
        return max(res, 1);
    }
};