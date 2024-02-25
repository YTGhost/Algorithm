// LeetCode究极班打卡
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i < s.length(); i++)
        {
            int l = i-1, r = i+1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);

            l = i, r = i+1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if(r-l-1 > ans.size()) ans = s.substr(l+1, r-l-1);
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string ans = "";
        for(int l = 0; l < n; l++)
            for(int i = 0; i + l < n; i++)
            {
                int j = i + l;
                if(i == j) dp[i][j] = 1;
                else if(j == i+1) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
                if(dp[i][j] && l + 1 > ans.length()) ans = s.substr(i, l+1);
            }
        return ans;
    }
};