class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        long dp[m][n];  //用int会溢出
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    if(i == 0 && j == 0)
                    {
                        return 0;
                    }
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }else if(i==0)
                {
                    dp[i][j] = dp[i][j-1];
                }else if(j==0)
                {
                    dp[i][j] = dp[i-1][j]; 
                }else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};