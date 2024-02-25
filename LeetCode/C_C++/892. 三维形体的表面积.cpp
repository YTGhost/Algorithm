class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0; i < grid.size(); i ++)
            for(int j = 0; j < grid[0].size(); j++)
            {
                int level = grid[i][j];
                if(level > 0){
                    area += 2 + (level << 2);
                    area -= i > 0 ? min(level, grid[i-1][j]) << 1 : 0;
                    area -= j > 0 ? min(level, grid[i][j-1]) << 1 : 0;
                }
            }
        return area;
    }
};