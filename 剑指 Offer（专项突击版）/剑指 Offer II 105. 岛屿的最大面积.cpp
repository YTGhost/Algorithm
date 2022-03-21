class Solution {
public:
    typedef pair<int, int> PII;
    int n, m;
    int res = 0;
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int sum = 0;
        queue<PII> q;
        q.push({i, j});
        grid[i][j] = 0;
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            sum++;
            int x = item.first, y = item.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    res = max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }
};