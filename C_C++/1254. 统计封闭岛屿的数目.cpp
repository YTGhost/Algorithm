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