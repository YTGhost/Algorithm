class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int p1[4] = {1, -1, 0, 0};
        int p2[4] = {0, 0, 1, -1};
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<int> t = {i, j};
                    q.push(t);
                }
            }

        bool hasOcean = false;
        bool hasLand = false;
        vector<int> point;
        while(!q.empty()){
            hasLand = true;
            point = q.front();
            int x = point[0];
            int y = point[1];
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int newX = x + p1[i];
                int newY = y + p2[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0) continue;
                grid[newX][newY] = grid[x][y] + 1;
                hasOcean = true;
                vector<int> t = {newX, newY}; 
                q.push(t);
            }
        }
        if(!hasOcean || !hasLand) return -1;

        return grid[point[0]][point[1]] - 1;
    }
};