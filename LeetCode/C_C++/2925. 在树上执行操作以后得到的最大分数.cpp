class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> g(n);
        g[0].push_back(-1);
        for(auto &edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        function<long long(int, int)> dfs = [&](int x, int fa) -> long long {
            if(g[x].size() == 1) {
                return values[x];
            }
            long long loss = 0;
            for(int y : g[x]) {
                if(y != fa) {
                    loss += dfs(y, x);
                }
            }
            return min((long long) values[x], loss);
        };
        return accumulate(values.begin(), values.end(), 0LL) - dfs(0, -1);
    }
};

class Solution {
public:
    long long res = 0;
    long long dfs(unordered_map<int, vector<int>>& m, vector<int>& values, int node, int preNode) {
        if(!m.count(node)) {
            return values[node];
        }
        int n = m[node].size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(m[node][i] == preNode) continue;
            sum += dfs(m, values, m[node][i], node);
        }
        if(sum == 0) {
            return values[node];
        }
        if(sum < values[node]) {
            res += values[node];
            values[node] = 0;
        } else {
            res += sum;
            sum = values[node];
        }
        return sum;
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += values[i];
        }
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n - 1; i++) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(m, values, 0, 0);
        return res;
    }
};