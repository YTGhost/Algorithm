class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        // f[i][j] 以s1的第i个结尾，并且以s2的第j个结尾的，ASCII值最大的公共子序列
        // s1的ASCII + s2的ASCII - 2 * res
        int sum1 = 0, sum2 = 0;
        for(auto c : s1)
            sum1 += c;
        for(auto c : s2)
            sum2 += c;
        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1] + s1[i-1];
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
                res = max(res, f[i][j]);
            }
        return sum1 + sum2 - 2 * res;
    }
};