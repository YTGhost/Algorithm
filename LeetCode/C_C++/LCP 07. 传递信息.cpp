class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        // f[i][j]为当前已经走了i步，所在位置为j的方案数
        vector<vector<int>> f(k+1, vector<int>(n, 0));
        f[0][0] = 1;
        for(int i = 1; i <= k; i++)
            for(auto r : relation) {
                int a = r[0], b = r[1];
                f[i][b] += f[i-1][a];
            }
        return f[k][n-1];
    }
};