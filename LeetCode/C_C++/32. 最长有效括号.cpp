class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.length();
        vector<int> dp(size+1, 0);
        int ans = 0;
        for(int i = 1; i <= size; i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(') dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else{
                    if(i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') dp[i] = dp[i-1] + 2 + (i-dp[i-1] > 2 ? dp[i-dp[i-1]-2] : 0);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};