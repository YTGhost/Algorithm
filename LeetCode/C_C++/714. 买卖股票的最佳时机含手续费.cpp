class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        const int inf = 0x3f;
        int f[n + 1][2];
        memset(f, -inf, sizeof(f));
        f[0][0] = 0;
        for(int i = 0; i < n; i++) {
            f[i + 1][1] = max(f[i][1], f[i][0] - prices[i]);
            f[i + 1][0] = max(f[i][0], f[i][1] + prices[i] - fee);
        }
        return f[n][0];
    }
};