class Solution {
public:
    int f[20005];
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int cnt0 = s[0] - '0';
        int cnt1 = 1 - cnt0;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                cnt1 = min(cnt0, cnt1) + 1;
            } else {
                cnt1 = min(cnt0, cnt1);
                cnt0++;
            }
        }
        return min(cnt0, cnt1);
    }
};