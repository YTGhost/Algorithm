class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w, i);
            g[y].emplace_back(x, w, i);
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) {
                continue;
            }
            for (auto [y, w, _] : g[x]) {
                int new_dis = dx + w;
                if (new_dis < dis[y]) {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }

        vector<bool> res(m);
        if(dis[n - 1] == LLONG_MAX) {
            return res;
        }
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            for(auto [y, w, idx] : g[x]) {
                if(dis[y] + w != dis[x]) {
                    continue;
                }
                res[idx] = true;
                if(!vis[y]) {
                    dfs(y);
                }
            }
        };
        dfs(n - 1);
        return res;
    }
};