class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        int dp[size] = {0};
        int maxLength = 1;
        dp[0] = 1;
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};