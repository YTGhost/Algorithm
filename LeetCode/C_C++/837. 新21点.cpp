// 时间复杂度 O(N+KW)，超时。
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0) return 1.0;
        vector<double> dp(K+W, 0);

        for(int i = K; i <= K+W-1 && i <= N; i++) dp[i] = 1;
        for(int i = K-1; i >= 0; i--)
        {
            for(int j = 1; j <= W; j++)
            {
                dp[i] += dp[i+j];
            }
            dp[i] /= W;
        }
        return dp[0];
    }
};

// 时间复杂度 O(min(N,K+W))
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0) return 1.0;
        vector<double> dp(K+W, 0);

        for(int i = K; i <= K+W-1 && i <= N; i++) dp[i] = 1;
        dp[K-1] = 1.0 * min(N-K+1, W) / W;
        for(int i = K - 2; i >= 0; i --) dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        return dp[0];
    }
};