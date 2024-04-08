class Solution {
public:
    static const int N = 1e5 + 10;
    int p[N];
    int s[N];
    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
        memset(s, -1, sizeof(s));
        for(auto edge : edges) {
            int x = find(edge[0]), y = find(edge[1]);
            s[y] &= edge[2];
            if(x != y) {
                s[y] &= s[x];
                p[x] = y;
            }
        }
        vector<int> res;
        for(auto q : query) {
            int a = q[0], b = q[1];
            if(a == b) {
                res.push_back(0);
            } else if(find(a) == find(b)) {
                res.push_back(s[find(a)]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};