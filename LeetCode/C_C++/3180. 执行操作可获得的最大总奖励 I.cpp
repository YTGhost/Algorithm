class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        int res = 0;
        sort(rewardValues.begin(), rewardValues.end());
        int maxVal = rewardValues[n - 1];
        vector<vector<int>> f(n + 1, vector<int>(2 * maxVal));
        f[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2 * maxVal - 1; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= rewardValues[i - 1] && j < 2 * rewardValues[i - 1]) {
                    f[i][j] |= f[i - 1][j - rewardValues[i - 1]];
                }
            }
        }

        for (int i = 2 * maxVal - 1; i >= 0; i--) {
            if (f[n][i]) {
                res = i;
                break;
            }
        }
        return res;
    }
};