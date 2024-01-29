class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size(), cnt = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else {
                    cnt++;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nx = node.first + dx[j], ny = node.second + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if(q.size()) {
                res++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};

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