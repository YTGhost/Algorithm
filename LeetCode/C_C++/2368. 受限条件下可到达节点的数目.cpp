// dfs
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        unordered_set<int> s(restricted.begin(), restricted.end());
        for(auto edge : edges) {
            int x = edge[0], y = edge[1];
            if(!s.contains(x) && !s.contains(y)) {
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        function<int(int, int)> dfs = [&](int node, int fa) {
            int cnt = 1;
            for(auto item : g[node]) {
                if(item != fa) {
                    cnt += dfs(item, node);
                }
            }
            return cnt;
        };
        return dfs(0, -1);
    }
};

// bfs
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n, vector<int>(0));
        unordered_set<int> hash(restricted.begin(), restricted.end());
        for(auto edge : edges) {
            if(!hash.contains(edge[0]) && !hash.contains(edge[1])) {
                g[edge[0]].push_back(edge[1]);
                g[edge[1]].push_back(edge[0]);
            }
        }
        int res = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                int node = q.front();
                q.pop();
                hash.insert(node);
                for(auto item : g[node]) {
                    if(!hash.contains(item)) {
                        q.push(item);
                        res++;
                    }
                }
            }
        }
        return res;
    }
};