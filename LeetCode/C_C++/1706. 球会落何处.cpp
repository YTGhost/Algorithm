class Solution {
public:
    int n, m;
    int getRes(int t, vector<vector<int>>& grid) {
        int row = 0, c = t;
        while(row < n) {
            int nc = c + grid[row][c];
            if(nc < 0 || nc >= m) return -1;
            if(grid[row][c] != grid[row][nc]) return -1;
            c = nc;
            row++;
        }
        return c;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) res[i] = getRes(i, grid);
        return res;
    }
};