class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        vector<int> res(n, -1);
        res[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minq;
        minq.push({0, 0});
        while (!minq.empty()) {
            auto [dist, x] = minq.top();
            minq.pop();
            if (dist > res[x]) {
                continue;
            }
            for (auto &[y, d] : g[x]) {
                int newDist = dist + d;
                if (newDist < disappear[y] && (res[y] < 0 || newDist < res[y])) {
                    res[y] = newDist;
                    minq.push({newDist, y});
                }
            }
        }
        return res;
    }
};