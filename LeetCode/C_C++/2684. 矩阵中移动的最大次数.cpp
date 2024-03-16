class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        function<void(int, int)> dfs = [&](int i, int j) {
            res = max(res, j);
            if(j == n - 1) return;
            for(int k = -1; k <= 1; k++) {
                int t = i + k;
                if(t >= 0 && t < m && grid[t][j + 1] > grid[i][j]) {
                    dfs(t, j + 1);
                }
            }
            grid[i][j] = 0;
        };
        for(int i = 0; i < m; i++) {
            dfs(i, 0);
        }
        return res;
    }
};