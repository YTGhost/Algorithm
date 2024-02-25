class Solution {
public:
    int visit[20][20];
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int sum = grid[x][y];
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || grid[nx][ny] == 0) continue;
            visit[nx][ny] = 1;
            sum = max(sum, grid[x][y] + dfs(nx, ny, grid));
            visit[nx][ny] = 0;
        }
        return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                visit[i][j] = 1;
                res = max(res, dfs(i, j, grid));
                visit[i][j] = 0;
            }
        }
        return res;
    }
};