class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        int res = INT_MAX;
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0x3f3f3f3f));
        for(int i = 0; i < n; i++) {
            f[0][i] = 0;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + grid[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            res = min(res, f[m - 1][i] + grid[m - 1][i]);
        }
        return res;
    }
};