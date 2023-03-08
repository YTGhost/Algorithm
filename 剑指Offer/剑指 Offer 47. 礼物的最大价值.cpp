class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

// 一维 
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(n+1, 0);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                f[j] = max(f[j], f[j-1]) + grid[i-1][j-1];
            }
        return f[n];
    }
};

// 二维
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                f[i][j] = max(f[i-1][j], f[i][j-1]) + grid[i-1][j-1];
            }
        return f[m][n];
    }
};