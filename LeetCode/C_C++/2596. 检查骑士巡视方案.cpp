class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        int x, y, visited = 1;
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    x = i, y = j;
                }
            }
        }

        while(true) {
            bool flag = false;
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == grid[x][y] + 1) {
                    x = nx, y = ny;
                    visited++;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                break;
            }
        }
        cout << visited << endl;
        return visited == n * n;
    }
};