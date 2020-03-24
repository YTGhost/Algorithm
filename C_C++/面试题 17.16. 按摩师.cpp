class Solution {
public:
    int massage(vector<int>& nums) {
        // 空间O(N)做法
        // if(nums.size() == 0) return 0;
        // if(nums.size() == 1) return nums[0];
        // int dp[nums.size()];
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for(int i = 2; i < nums.size(); i++)
        // {
        //     dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        // }
        // return dp[nums.size()-1];
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = max(b, a + nums[i]);
            a = b;
            b = temp;
        }
        return b;
    }
};