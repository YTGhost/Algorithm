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