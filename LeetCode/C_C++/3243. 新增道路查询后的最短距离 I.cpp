class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n - 1);
        for (int i = 0; i < n - 1; i++) {
            g[i].push_back(i + 1);
        }
        vector<int> vis(n - 1, -1);
        function<int(int)> bfs = [&](int i) {
            vector<int> q = {0};
            for (int step = 1; ; step++) {
                vector<int> nxt;
                for (int x : q) {
                    for (int y : g[x]) {
                        if (y == n - 1) {
                            return step;
                        }
                        if (vis[y] != i) {
                            vis[y] = i;
                            nxt.push_back(y);
                        }
                    }
                }
                q = move(nxt);
            }
        };
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            g[x].push_back(y);
            res[i] = bfs(i);
        }
        return res;
    }
};