class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size(), INF = 0x3f3f3f3f;
        vector<vector<int>> f(n+1, vector<int>(3));
        f[0][0] = f[0][1] = -INF;
        f[0][2] = 0;
        for(int i = 1; i <= n; i++)
        {
            f[i][0] = max(f[i-1][0], f[i-1][2] - prices[i-1]);
            f[i][1] = f[i-1][0] + prices[i-1];
            f[i][2] = max(f[i-1][2], f[i-1][1]);
        }
        return max(f[n][1], f[n][2]);
    }
};