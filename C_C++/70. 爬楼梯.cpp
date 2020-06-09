// 滚动数组优化
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c = 1;
        for(int i = 1; i < n; i++)
        {
            a = b;
            b = c;
            c = (a + b);
        }
        return c;
    }
};

// 正常dp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        {
            return 1;
        }
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++ )
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};