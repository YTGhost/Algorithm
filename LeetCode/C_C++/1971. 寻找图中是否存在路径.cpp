class Solution {
public:
    static const int N = 200010;
    int p[N];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 1; i <= n; i++) p[i] = i;
        for(auto &edge : edges) {
            p[find(edge[0])] = find(edge[1]);
        }
        return find(source) == find(destination);
    }
};