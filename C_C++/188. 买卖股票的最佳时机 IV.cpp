class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[n + 1][k + 2][2];
        memset(f, 0xc0, sizeof(f));
        for(int i = 1; i < k + 2; i++) {
            f[0][i][0] = 0;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < k + 2; j++) {
                f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
                f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - prices[i]);
            }
        }
        return f[n][k + 1][0];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), INF = 0x3f3f3f3f;
        if(n == 0) return 0;
        vector<vector<int>> f(n+1, vector<int>(k+1, -INF));
        f[0][0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = k; j >= 1; j--)
            {
                f[j][0] = max(f[j][0], f[j][1] + prices[i-1]);
                f[j][1] = max(f[j][1], f[j-1][0] - prices[i-1]);
            }
        int res = 0;
        for(int i = 0; i <= k; i++) res = max(res, f[i][0]);
        return res;
    }
};