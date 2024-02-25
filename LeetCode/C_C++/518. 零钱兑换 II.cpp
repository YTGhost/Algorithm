class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1));
        f[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                int coin = coins[i-1];
                for(int k = 0; k * coin <= j; k++) {
                    f[i][j] += f[i-1][j - k*coin];
                }
            }
        }
        return f[n][amount];
    }
};

// 二维朴素做法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        int t = max(n, m);

        vector<vector<int>> f(t+1, vector<int>(t+1, 0));

        for(int i = 0; i <= n; i++) f[i][0] = 1;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 0; k*coins[i-1] <= j; k++)
                    f[i][j] += f[i-1][j-k*coins[i-1]];
        return f[n][m];
    }
};

// 二维优化做法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        int t = max(n, m);

        vector<vector<int>> f(t+1, vector<int>(t+1, 0));

        for(int i = 0; i <= n; i++) f[i][0] = 1;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                f[i][j] = f[i-1][j];
                if(j >= coins[i-1]) f[i][j] += f[i][j-coins[i-1]];
            }
                
        return f[n][m];
    }
};

// 优化为一维做法
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        int t = max(n, m);

        vector<int> f(t+1, 0);

        f[0] = 1;

        for(int i = 1; i <= n; i++)
            for(int j = coins[i-1]; j <= m; j++)
                f[j] += f[j-coins[i-1]];
        return f[m];
    }
};