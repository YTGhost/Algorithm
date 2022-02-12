class Solution {
public:
    typedef pair<int, int> PII;
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<PII> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            int x = item.first, y = item.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || !grid[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }
};