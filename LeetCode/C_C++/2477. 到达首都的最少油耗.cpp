class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> g(roads.size() + 1);
        for(auto road : roads) {
            g[road[0]].push_back(road[1]);
            g[road[1]].push_back(road[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int x, int fa) -> int {
            int cnt = 1;
            for(auto y : g[x]) {
                if(y != fa) {
                    cnt += dfs(y, x);
                }
            }
            if(x) {
                res += (cnt - 1) / seats + 1;
            }
            return cnt;
        };
        dfs(0, -1);
        return res;
    }
};