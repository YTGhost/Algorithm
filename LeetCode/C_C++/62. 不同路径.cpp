class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = 1;
        for(int i = 1; i < n; i++) {
            f[0][i] = 1;
        }
        for(int i = 1; i < m; i++) {
            f[i][0] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};

class Solution {
public:
    int a[101][101];
    void init(int m, int n)
    {
        for(int i = 1; i<= m; i++)
        {
            a[i][1] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            a[1][i] = 1;
        }
    }

    int getPaths(int m, int n)
    {
        if(a[m][n] != 0)
        {
            return a[m][n];
        }

        return a[m][n] = getPaths(m-1, n) + getPaths(m, n-1);
    }

    int uniquePaths(int m, int n) {
        init(m, n);
        return getPaths(m, n);
    }
};