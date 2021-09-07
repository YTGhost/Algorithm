class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int lcnt = 0, rcnt = 0;
        for(int i = 0, j = 0; i < s.length(); j++) {
            if(s[j] == 'L') lcnt++;
            else if(s[j] == 'R') rcnt++;
            if(lcnt == rcnt) {
                res++;
                lcnt = rcnt = 0;
                i = j + 1;
            }
        }
        return res;
    }
};