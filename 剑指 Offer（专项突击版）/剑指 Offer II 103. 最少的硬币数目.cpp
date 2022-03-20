class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, 0x3f3f3f3f);
        f[0] = 0;
        for(int i = 0; i < n; i++) {
            int coin = coins[i];
            for(int j = coin; j <= amount; j++) {
                if(f[j - coin] == 0x3f3f3f3f) continue;
                f[j] = min(f[j], f[j - coin] + 1);
            }
        }
        return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
    }
};