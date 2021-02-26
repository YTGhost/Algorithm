class Solution {
public:
    int map[128];
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), res = 0;
        while(r < n)
        {
            map[s[r]]++;
            while(map[s[r]] > 1) map[s[l++]]--;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};