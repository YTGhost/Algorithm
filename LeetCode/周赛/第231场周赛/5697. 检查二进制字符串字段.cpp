class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int sign = 1;
        if(n == 1) {
            if(s[0] == '1') return true;
            else return false;
        }
        for(int i = 1; i < n; i++)
        {
            if(sign && s[i] == '0') {
                sign = 0;
            } else if(!sign && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};