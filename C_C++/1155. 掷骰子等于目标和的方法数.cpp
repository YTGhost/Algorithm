class Solution {
public:
    const int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int _k, int target) {
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                for(int k = 1; k <= _k; k++) {
                    if(j >= k) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
                    }
                }
            }
        }
        return f[n][target];
    }
};