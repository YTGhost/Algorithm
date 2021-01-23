class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, count = 0, temp = INT_MIN;
        for(auto num : nums)
            if(num > temp) {
                count++;
                temp = num;
            } else {
                res = max(res, count);
                count = 1;
                temp = num;
            }
        return max(res, count);
    }
};