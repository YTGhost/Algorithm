class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        vector<int> rowMax(n);
        vector<int> colMax(n);
        for (int i = 0; i < n; i++) {
            int maxRowVal = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[i] = max(colMax[i], grid[j][i]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(rowMax[i], colMax[j]);
            }
        }
        return res - sum;
    }
};