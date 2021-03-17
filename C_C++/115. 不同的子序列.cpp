class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) return 0;
        vector<vector<long>> f(n+1, vector<long>(m+1));
        for(int i = 0; i < n; i++)
            f[i][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(j > i) continue;
                if(s[i-1] == t[j-1]) {
                    f[i][j] = f[i-1][j-1] + f[i-1][j];
                } else {
                    f[i][j] = f[i-1][j];
                }
            }
        return f[n][m];
    }
};