class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            f[i][i] = true;
        }
        int res = 0, l = 0, r = 0;
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                f[i][j] = s[i] == s[j];
                if(j > i + 2) {
                    f[i][j] = f[i][j] && f[i + 1][j - 1];
                }
                if(f[i][j]) {
                    int len = j - i + 1;
                    if(len > res) {
                        cout << len << endl;
                        res = len;
                        l = i, r = j;
                    }
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};

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