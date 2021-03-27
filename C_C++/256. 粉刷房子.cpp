class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> f(n+1, vector<int>(3));
        // f[i][j]，前i个房子，最后一个房子的颜色为j
        for(int i = 1; i <= n; i++)
        {
            f[i][0] = min(f[i-1][1], f[i-1][2]) + costs[i-1][0];
            f[i][1] = min(f[i-1][0], f[i-1][2]) + costs[i-1][1];
            f[i][2] = min(f[i-1][0], f[i-1][1]) + costs[i-1][2];
        }
        return min(f[n][0], min(f[n][1], f[n][2]));
    }
};