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