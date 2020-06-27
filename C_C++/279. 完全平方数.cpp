// 一维优化做法
class Solution {
public:
    int numSquares(int n) {
        int m;
        vector<int> v(n+1);
        vector<int> f(n+1, 1e9);
        int cnt = 1; 
        while(cnt*cnt <= n)
        {
            v[cnt] = cnt*cnt;
            cnt++;
        }
        m = --cnt;
        f[0] = 0;
        for(int i = 1; i <= m; i++)
            for(int j = v[i]; j <= n; j++)
                f[j] = min(f[j], f[j-v[i]] + 1);
        return f[n];
    }
};