class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for(auto num : nums)
        {
            if(sum < 0) sum = 0;
            sum += num;
            res = max(res, sum);
        }
        return res;
    }
};