class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                    while(!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = t.first + dx[k], ny = t.second + dy[k];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !vis[nx][ny]) {
                                q.push({nx, ny});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(dfs(grid, i, j)){
                    sum++;
                }
            }
        }
        return sum;
    }
    int dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0'){
            return 0;
        }
        grid[r][c] = '0';
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        return 1;
    }
};