class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }
        return f[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for(int i = 1; i <= n; i++) {
            int t = INT_MAX;
            for(int j = 1; j * j <= i; j++) {
                t = min(t, f[i - j*j]);
            }
            f[i] = t + 1;
        }
        return f[n];
    }
};

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