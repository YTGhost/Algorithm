class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        int res = 1;
        int l = 0, r = 1;
        while (r < n) {
            if (s[r] == s[r - 1] + 1) {
                res = max(res, r - l + 1);
                r++;
            } else {
                l = r;
                r = l + 1;
            }
        }
        res = max(res, n - l);
        return res;
    }
};