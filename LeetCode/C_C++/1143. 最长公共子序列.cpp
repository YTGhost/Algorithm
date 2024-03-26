class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            char c1 = text1[i - 1];
            for(int j = 1; j <= m; j++) {
                char c2 = text2[j - 1];
                if (c1 == c2) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(text1[i-1] == text2[j-1]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1); 
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
        return f[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length(), size2 = text2.length();
        vector<vector<int>> f(size1+1, vector<int>(size2+1, 0));
        for(int i = 1; i <= size1; i++)
            for(int j = 1; j <= size2; j++)
            {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                if(text1[i-1] == text2[j-1]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            }
        return f[size1][size2];
    }
};