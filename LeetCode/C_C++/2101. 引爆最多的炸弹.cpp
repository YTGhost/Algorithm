class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        function<bool(int, int)> check = [&](int i, int j) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            long long x2 = bombs[j][0], y2 = bombs[j][1];
            if (abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2) > r * r) {
                return false;
            }
            return true;
        };
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && check(i, j)) {
                    g[i].push_back(j);
                }
            }
        }
        vector<int> vis(n);
        function<int(int)> dfs = [&](int idx) {
            if (vis[idx]) return 0;
            vis[idx] = true;
            int res = 1;
            for (auto x : g[idx]) {
                if (vis[x]) continue;
                res += dfs(x);
            }
            return res;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            vis = vector<int>(n, 0);
            res = max(res, dfs(i));
        }
        return res;
    }
};