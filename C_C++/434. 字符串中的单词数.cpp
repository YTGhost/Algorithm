class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool flag = false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && flag) {
                res++;
                flag = false;
            } else if(s[i] != ' ') {
                flag = true;
            }
        }
        if(flag) res++;
        return res;
    }
};