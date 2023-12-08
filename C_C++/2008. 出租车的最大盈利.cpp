class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> g(n + 1);
        for(auto ride : rides) {
            int start = ride[0], end = ride[1], tip = ride[2];
            g[end].push_back({start, end - start + tip});
        }
        vector<long long> f(n + 1);
        for(int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            for(int j = 0; j < g[i].size(); j++) {
                int start = g[i][j].first;
                f[i] = max(f[i], f[start] + g[i][j].second);
            }
        }
        return f[n];
    }
};