class Solution {
public:
    typedef pair<int, int> PII;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        queue<PII> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            int x = item.first, y = item.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == -1) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return mat;
    }
};