class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                cnt++;
            }
        }
        long long res = ((long long)cnt * (cnt - 1)) / 2 + cnt;
        return res;
    }
};