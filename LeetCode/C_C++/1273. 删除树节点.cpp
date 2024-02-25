class Solution {
public:
    static const int N = 10005;
    int idx;
    int he[N], e[N], ne[N];
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
    }
    pair<int, int> dfs(int node, vector<int>& value) {
        int totalSum = 0, totalNodes = 0;
        for(int i = he[node]; i != -1; i = ne[i]) {
            int v = e[i];
            auto [sum, nodes] = dfs(v, value);
            totalSum += sum;
            totalNodes += nodes;
        }
        totalSum += value[node];
        totalNodes += 1;
        if(totalSum == 0) {
            return {0, 0};
        }
        return {totalSum, totalNodes};
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        memset(he, -1, sizeof(he));
        for(int i = 1; i < parent.size(); i++) {
            add(parent[i], i);
        }
        auto [_, res] = dfs(0, value);
        return res;
    }
};