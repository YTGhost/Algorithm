class Solution {
public:
    int MOD = 1337;
    int dfs(int a, vector<int>& b, int u) {
        if(u == -1) return 1;
        return qpow(dfs(a, b, u-1), 10) * qpow(a, b[u]) % MOD;
    }
    int qpow(int a, int b) {
        int res = 1;
        a %= MOD;
        while(b) {
            if(b & 1) res = (long long)res * a % MOD;
            b >>= 1;
            a = a * a % MOD;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);
    }
};