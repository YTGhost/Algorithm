class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(string word : wordDict) set.insert(word);

        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;

        for(int i = 1; i <= s.length(); i++)
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && set.count(s.substr(j, i-j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        return dp[s.length()];
    }
};