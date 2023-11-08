class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        vector<int> cnt(2);
        int res = 0, n = s.size();
        for(int l = 0, r = 0; l < n && r < n;) {
            while(r < n && s[r] == '0') {
                cnt[0]++;
                r++;
            }
            while(r < n && s[r] == '1') {
                cnt[1]++;
                r++;
                if(cnt[0] >= cnt[1]) {
                    res = max(res, cnt[1] * 2);
                }
            }
            cnt[0] = 0;
            cnt[1] = 0;
            l = r;
        }
        return res;
    }
};