class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(i, j, grid));
            }
        }
        return maxArea;
    }
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int num = 1;
        grid[i][j] = 0;
        num += dfs(i+1, j, grid) + dfs(i, j+1, grid) + dfs(i-1, j, grid) + dfs(i, j-1, grid);
        return num;
    }
};