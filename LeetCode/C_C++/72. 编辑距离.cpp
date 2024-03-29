class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= m; i++) {
            f[0][i] = i;
        }
        for(int i = 1; i <= n; i++) {
            f[i][0] = i;
        }
        for(int i = 1; i <= n; i++) {
            char c1 = word1[i - 1];
            for(int j = 1; j <= m; j++) {
                char c2 = word2[j - 1];
                if (c1 == c2) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}) + 1;
                }
            }
        }
        return f[n][m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // f[i][j] word1前i个转换成word2前j个需要的最少操作数
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++) f[i][0] = i;
        for(int j = 1; j <= m; j++) f[0][j] = j;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1];
                else f[i][j] = min(min(f[i-1][j-1], f[i-1][j]), f[i][j-1]) + 1;
            }
        return f[n][m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                // dp[i-1][j]是删除，dp[i][j-1]是插入,dp[i-1][j-1]是替换
                else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        return dp[n][m];
    }
};