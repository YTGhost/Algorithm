class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long res = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == '0') {
                res += i - idx;
                idx++;
            }
        }
        return res;
    }
};