class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, 101);
        dp[0] = 0;
        for(int i = 0; i <= T; i++)
            for(auto clip : clips)
            {
                if(clip[0] < i && clip[1] >= i)
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
            }
        return dp[T] == 101 ? -1 : dp[T];
    }
};