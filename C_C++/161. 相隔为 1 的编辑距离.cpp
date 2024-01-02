class Solution {
public:
    bool check(string s, string t) {
        int n = s.size(), m = t.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                return s.substr(i, n - i + 1) == t.substr(i + 1, n - i);
            }
        }
        return true;
    }
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        int cnt = n - m;
        if(cnt == -1) {
            return check(s, t);
        } else if(cnt == 1) {
            return check(t, s);
        } else if(cnt == 0) {
            bool flag = false;
            for(int i = 0; i < n; i++) {
                if(s[i] != t[i]) {
                    if(flag) {
                        return false;
                    } else {
                        flag = true;
                    }
                }
            }
            return flag;
        }
        return false;
    }
};