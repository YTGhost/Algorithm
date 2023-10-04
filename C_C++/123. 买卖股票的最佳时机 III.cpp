class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n + 1][4][2];
        memset(f, 0xc0, sizeof(f));
        for(int i = 1; i < 4; i++) {
            f[0][i][0] = 0;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < 4; j++) {
                f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
                f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - prices[i]);
            }
        }
        return f[n][3][0];
    }
};