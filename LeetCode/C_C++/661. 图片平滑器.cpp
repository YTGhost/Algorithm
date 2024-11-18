class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<vector<int>> res(m, vector<int>(n));
        function<int(int, int)> cal = [&](int x, int y) {
            int sum = img[x][y];
            int cnt = 1;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                cnt++;
                sum += img[nx][ny];
            }
            return sum / cnt;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = cal(i, j);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        function<int(int, int)> handle = [&](int x, int y) {
            int sum = img[x][y];
            int cnt = 1;
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    cnt++;
                    sum += img[nx][ny];
                }
            }
            return sum / cnt;
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = handle(i, j);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> sum(n + 10, vector<int>(m + 10));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a = max(0, i - 1), b = max(0, j - 1);
                int c = min(n - 1, i + 1), d = min(m - 1, j + 1);
                int cnt = (c - a + 1) * (d - b + 1);
                int total = sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b];
                res[i][j] = total / cnt;
            }
        }
        return res;
    }
};