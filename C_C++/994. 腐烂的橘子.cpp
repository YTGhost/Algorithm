class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> p1 = {1, -1, 0, 0};
        vector<int> p2 = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid.front().size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }
        int minute = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < p1.size(); j++)
                {
                    int x = q.front().first + p1[j];
                    int y = q.front().second + p2[j];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push(make_pair(x, y));
                    }
                }
                q.pop();
            }
            if(!q.empty())  minute++;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return minute;
    }
};