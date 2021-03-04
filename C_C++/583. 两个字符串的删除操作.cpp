class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        // f[i][j] 以word1的第i个字母结尾，word2的第j个字母结尾的最长公共子序列的长度
        // res word1的长度 + word2的长度 - 2 * f[n][m]
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
        return n + m - 2 * f[n][m];
    }
};