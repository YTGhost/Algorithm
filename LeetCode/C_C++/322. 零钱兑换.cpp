class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 0x3f3f3f3f);
        f[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(auto coin : coins) {
                if(i >= coin) {
                    f[i] = min(f[i], f[i - coin] + 1);
                }
            }
        }
        return f[amount] == 0x3f3f3f3f ? -1 : f[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int dp[amount + 1];
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            dp[i] = amount + 1;
            for(int j = 0; j < coins.size(); j++)
            {
                if(i >= coins[j])   dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};