class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        unordered_map<int, int> rows, cols;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && (rows[i] > 1 || cols[j] > 1)) {
                    res++;
                }
            }
        }
        return res;
    }
};