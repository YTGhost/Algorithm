class Solution {
public:
    int p[10005];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void toUnion(int x, int y) {
        p[find(x)] = find(y);
    }
    struct Edge {
        int t, x, y;
        bool operator < (const Edge& e) const {
            return t < e.t;
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        for(int i = 0; i <= row * col; i++) {
            p[i] = i;
        }
        vector<Edge> edges;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int id = i * col + j;
                if(i > 0) {
                    edges.push_back({abs(heights[i][j] - heights[i - 1][j]), id - col, id});
                }
                if(j > 0) {
                    edges.push_back({abs(heights[i][j] - heights[i][j - 1]), id - 1, id});
                }
            }
        }
        sort(edges.begin(), edges.end());
        for(auto& edge : edges) {
            toUnion(edge.x, edge.y);
            if(find(0) == find(row * col - 1)) {
                return edge.t;
            }
        }
        return 0;
    }
};

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