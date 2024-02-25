class Solution {
public:
    unordered_map<long, int> m;
    int integerReplacement(int n) {
        return dfs(n);
    }
    int dfs(long n) {
        if(n == 1) return 0;
        if(m[n]) return m[n];
        int res = n % 2 == 0 ? dfs(n / 2) : min(dfs(n + 1), dfs(n - 1));
        m[n] = ++res;
        return res;
    }
};