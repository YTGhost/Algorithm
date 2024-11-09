class NeighborSum {
public:
    unordered_map<int, int> adjacent;
    unordered_map<int, int> diagonal;
    NeighborSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                if (i != 0) {
                    adjacent[x] += grid[i - 1][j];
                    if (j != n - 1) {
                        diagonal[x] += grid[i - 1][j + 1];
                    }
                    if (j != 0) {
                        diagonal[x] += grid[i - 1][j - 1];
                    }
                }
                if (i != n - 1) {
                    adjacent[x] += grid[i + 1][j];
                    if (j != n - 1) {
                        diagonal[x] += grid[i + 1][j + 1];
                    }
                    if (j != 0) {
                        diagonal[x] += grid[i + 1][j - 1];
                    }
                }
                if (j != 0) {
                    adjacent[x] += grid[i][j - 1];
                }
                if (j != n - 1) {
                    adjacent[x] += grid[i][j + 1];
                }
            }
        }
    }
    
    int adjacentSum(int value) {
        return adjacent[value];
    }
    
    int diagonalSum(int value) {
        return diagonal[value];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */