class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), res = 0;
        for(int i = 0; i < n; i++) {
            res += (s[i] - '0') ^ (i & 1);
        }
        return min(res, n - res);
    }
};