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