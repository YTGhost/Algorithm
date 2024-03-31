class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int cnt = 0;
        function<bool(int)> check = [&](int idx) {
            return s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u';
        };
        for(int i = 0; i < k; i++) {
            if(check(i)) {
                cnt++;
            }
        }
        int res = cnt;
        for(int i = k; i < n; i++) {
            if(check(i)) {
                cnt++;
            }
            if(check(i - k)) {
                cnt--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};