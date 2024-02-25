class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        for(auto road : roads) {
            int a = road[0], b = road[1];
            connect[a][b] = true;
            connect[b][a] = true;
            degree[a]++;
            degree[b]++;
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                rank += connect[i][j] ? -1 : 0;
                res = max(res, rank);
            }
        }
        return res;
    }
};