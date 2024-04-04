class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> g(n);
        for(auto edge : edges) {
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            for(auto y : g[x]) {
                if(!vis[y]) {
                    dfs(y);
                }
            }
        };
        for(int i = 0; i < n; i++) {
            vis = vector<bool>(n, false);
            dfs(i);
            vis[i] = false;
            for(int j = 0; j < n; j++) {
                if(vis[j]) {
                    res[i].push_back(j);
                }
            }
        }
        return res;
    }
};