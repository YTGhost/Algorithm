class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k == 0) return s;
        int n = s.length();
        function<void(int)> change = [&](int idx) {
            int cnt = min(s[idx] - 'a', 'z' - s[idx] + 1);
            if (k >= cnt) {
                k -= cnt;
                s[idx] = 'a';
            } else {
                s[idx] -= k;
                k = 0;
            }
        };
        for(int i = 0; i < n; i++) {
            if(k) {
                change(i);
            }
        }
        return s;
    }
};