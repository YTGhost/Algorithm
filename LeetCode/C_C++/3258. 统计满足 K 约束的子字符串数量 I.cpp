class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0, n = s.length();
        int l = 0, r = 0;
        vector<int> cnt(2);
        while (r < n) {
            int idx = s[r] - '0';
            cnt[idx]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[l] - '0']--;
                l++;
            }
            res += r - l + 1;
            r++;
        }
        return res;
    }
};