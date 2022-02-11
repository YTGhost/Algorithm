class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int l = 0, r = 0, res = 0, n = s.length();
        while(r < n) {
            hash[s[r]]++;
            while(l <= r && hash[s[r]] > 1) {
                hash[s[l++]]--;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};