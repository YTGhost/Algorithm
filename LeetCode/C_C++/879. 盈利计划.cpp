class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size();
        // 在前i种工作中，员工总数为j, 至少盈利k
        vector<vector<vector<int>>> f(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        f[0][0][0] = 1;
        for(int i = 1; i <= len; i++) {
            int a = group[i-1], b = profit[i-1];
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <= minProfit; k++) {
                    if(j < a) f[i][j][k] = f[i-1][j][k];
                    else {
                        f[i][j][k] = (f[i-1][j][k] + f[i-1][j-a][max(0, k-b)]) % 1000000007;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i <= n; i++) {
            res = (res + f[len][i][minProfit]) % 1000000007;
        }
        return res;
    }
};