class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> f(n + 1, vector<long long>(2, 0));
        f[1][0] = energyDrinkA[0];
        f[1][1] = energyDrinkB[0];
        for (int i = 2; i <= n; i++) {
            f[i][0] = max(f[i - 1][0] + energyDrinkA[i - 1], f[i - 2][1] + energyDrinkA[i - 1]);
            f[i][1] = max(f[i - 1][1] + energyDrinkB[i - 1], f[i - 2][0] + energyDrinkB[i - 1]);
        }
        return max(f[n][0], f[n][1]);
    }
};