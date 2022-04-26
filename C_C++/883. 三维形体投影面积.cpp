class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xySize = 0, yzSize = 0, zxSize = 0;
        for(int i = 0; i < n; i++) {
            int yzHight = 0, zxHight = 0;
            for(int j = 0; j < n; j++) {
                xySize += grid[i][j] > 0 ? 1 : 0;
                yzHight = max(yzHight, grid[i][j]);
                zxHight = max(zxHight, grid[j][i]);
            }
            yzSize += yzHight;
            zxSize += zxHight;
        }
        return xySize + yzSize + zxSize;
    }
};