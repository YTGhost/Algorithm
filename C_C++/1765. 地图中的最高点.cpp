class Solution {
public:
    typedef pair<int, int> PII;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        queue<PII> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1;
                }
            }
        }
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            int x = item.first, y = item.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(isWater[nx][ny] != -1) continue;
                isWater[nx][ny] = 1;
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return res;
    }
};