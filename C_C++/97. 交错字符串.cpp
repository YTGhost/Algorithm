class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), t = s3.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        if(n + m != t) return false;
        f[0][0] = 1;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                int p = i + j - 1;
                if(i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if(j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};