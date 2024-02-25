// 每日一题打卡
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]) {
                    for(int k = 0; k < 4; k++)
                    {
                        int newX = j + dx[k];
                        int newY = i + dy[k];
                        if(newX < 0 || newY < 0 || newX >= m || newY >= n || !grid[newY][newX]) {
                            res++;
                        }
                    }
                }
            }
        return res;
    }
};

class Solution {
public:
    int ans;
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0) dfs(i, j, grid);
            }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            ans++;
            return;
        }
        if(grid[i][j] == -1) return;
        grid[i][j] = -1;
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
    }
};