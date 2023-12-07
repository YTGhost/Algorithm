class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> g(n);
        for(auto conn : connections) {
            int x = conn[0], y = conn[1];
            g[x].push_back({y, 1});
            g[y].push_back({x, 0});
        }
        function<int(int, int)> dfs = [&](int x, int fa) -> int {
            int sum = 0;
            for(int i = 0; i < g[x].size(); i++) {
                if(g[x][i].first != fa) {
                    sum += g[x][i].second + dfs(g[x][i].first, x);
                }
            }
            return sum;
        };
        return dfs(0, -1);
    }
};