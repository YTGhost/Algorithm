class Solution {
public:
    int p[100005];
    unordered_map<int, int> m;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        for(int i = 0; i < n; i++) {
            p[i] = i;
        }
        for(auto& edge : edges) {
            p[find(edge[1])] = find(edge[0]);
        }
        for(int i = 0; i < n; i++) {
            m[find(i)]++;
        }
        for(int i = 0; i < n; i++) {
            res += n - m[find(i)];
        }
        return res / 2;
    }
};