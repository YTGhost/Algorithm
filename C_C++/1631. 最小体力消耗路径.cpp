class Solution {
public:
    int p[10010];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void connect(int x, int y) {
        p[find(x)] = find(y);
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < n * m; i++) p[i] = i;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int id = i * m + j;
                if(i > 0) edges.emplace_back(id - m, id, abs(heights[i][j] - heights[i-1][j]));
                if(j > 0) edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j-1]));
            }
        sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });
        int res = 0;
        for(const auto [x, y, v] : edges)
        {
            connect(x, y);
            if(isConnected(0, n * m - 1)) {
                res = v;
                break;
            }
        }
        return res;
    }
};