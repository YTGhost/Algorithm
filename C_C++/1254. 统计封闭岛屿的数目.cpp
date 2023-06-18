class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if(x < 0 || x >= n || y < 0 || y >= m) {
                return false;
            }
            if(grid[x][y] != 0) {
                return true;
            }
            grid[x][y] = -1;
            bool a = dfs(x + 1, y);
            bool b = dfs(x, y + 1);
            bool c = dfs(x - 1, y);
            bool d = dfs(x, y - 1);
            return a && b && c && d;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && dfs(i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0){
                    int val = 1;
                    dfs(grid, i, j, val);
                    sum += val;
                }
            }
        }
        return sum;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& val){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            val = 0;
            return;
        }
        if(grid[r][c] == 1) return;
        grid[r][c] = 1;
        dfs(grid, r+1, c, val);
        dfs(grid, r-1, c, val);
        dfs(grid, r, c+1, val);
        dfs(grid, r, c-1, val);
    }
};