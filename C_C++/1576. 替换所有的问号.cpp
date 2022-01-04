class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '?') {
                for(char c = 'a'; c <= 'c'; c++) {
                    if(i > 0 && c == s[i-1] || c == s[i + 1] && i < s.length() - 1) {
                        continue;
                    }
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};