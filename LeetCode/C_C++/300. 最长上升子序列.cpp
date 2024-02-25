// AcWing基础班重做O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, 1);

        for(int i = 1; i <= size; i++)
            for(int j = 1; j < i; j++)
                if(nums[j-1] < nums[i-1]) dp[i] = max(dp[i], dp[j] + 1);
        int res = 0;
        for(int i = 1; i <= size; i++) res = max(res, dp[i]);
        return res;
    }
};

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