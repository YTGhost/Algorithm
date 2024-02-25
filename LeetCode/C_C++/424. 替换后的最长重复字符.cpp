class Solution {
public:
    int hash[26];
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        for(; r < n; r++)
        {
            int t = s[r] - 'A';
            hash[t]++;
            maxLen = max(maxLen, hash[t]);
            if(maxLen + k < r - l + 1) {
                hash[s[l++] - 'A']--;
            }
        }
        return r - l;
    }
};