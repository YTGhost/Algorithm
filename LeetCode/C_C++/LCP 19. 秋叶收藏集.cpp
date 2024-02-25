class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = leaves[0] == 'y';
        dp[0][1] = dp[0][2] = dp[1][2] = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            int isRed = leaves[i] == 'r';
            int isYellow = leaves[i] == 'y';
            dp[i][0] = dp[i-1][0] + isYellow;
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + isRed;
            if(i >= 2) dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + isYellow;
        }
        return dp[n-1][2];
    }
};