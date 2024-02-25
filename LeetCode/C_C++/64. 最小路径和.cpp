// 每日一题打卡
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) f[i][j] += grid[i][j];
                else if(i == 0) f[i][j] = f[i][j-1] + grid[i][j];
                else if(j == 0) f[i][j] = f[i-1][j] + grid[i][j];
                else f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        return f[m-1][n-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        int dp[m][n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i==0 && j==0)    dp[i][j] = grid.front().front();
                else if(i==0)       dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j==0)       dp[i][j] = dp[i-1][j] + grid[i][j];
                else                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];   
            }
        }
        return dp[m-1][n-1];
    }
};