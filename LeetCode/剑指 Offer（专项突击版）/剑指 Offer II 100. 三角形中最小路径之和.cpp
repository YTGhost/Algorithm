class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n - 1].size();
        vector<vector<int>> f(n, vector<int>(m, 0x3f3f3f3f));
        f[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < triangle[i].size(); j++) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < m; i++) {
            res = min(res, f[m - 1][i]);
        }
        return res;
    }
};