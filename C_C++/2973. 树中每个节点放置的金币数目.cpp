class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<long long> coin(n, 1);
        vector<vector<int>> g(n);
        for(auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        function<vector<int>(int, int)> dfs = [&](int x, int fa) -> vector<int> {
            vector<int> a = {cost[x]};
            for(int i = 0; i < g[x].size(); i++) {
                if(g[x][i] != fa) {
                    vector<int> t = dfs(g[x][i], x);
                    a.insert(a.end(), t.begin(), t.end());
                }
            }
            sort(a.begin(), a.end());
            int m = a.size();
            if(m >= 3) {
                coin[x] = max({(long long)a[m - 1] * a[m - 2] * a[m - 3], (long long)a[0] * a[1] * a[m - 1], 0LL});
            }
            if(m > 5) {
                a = {a[m - 1], a[m - 2], a[m - 3], a[0], a[1]};
            }
            return a;
        };
        dfs(0, -1);
        return coin;
    }
};