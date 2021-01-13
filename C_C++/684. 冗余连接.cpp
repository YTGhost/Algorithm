class Solution {
public:
    vector<int> p;
    int find(vector<vector<int>>& edges, int x) {
        if(p[x] != x) p[x] = find(edges, p[x]);
        return p[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        for(int i = 0; i <= n; i++) p.push_back(i);
        for(auto edge : edges)
        {
            int a = find(edges, edge[0]), b = find(edges, edge[1]);
            if(a != b) {
                p[a] = b;
            } else {
                res = edge;
                break;
            }
        }
        return res;
    }
};