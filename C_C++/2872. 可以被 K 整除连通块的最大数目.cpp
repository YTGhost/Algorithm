class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for(auto &edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int res = 0;
        function<long long(int, int)> dfs = [&](int x, int fa) -> long long {
            long long sum = values[x];
            for(int y : g[x]) {
                if(y != fa) {
                    sum += dfs(y, x);
                }
            }
            res += sum % k == 0;
            return sum;
        };
        dfs(0, -1);
        return res;
    }
};