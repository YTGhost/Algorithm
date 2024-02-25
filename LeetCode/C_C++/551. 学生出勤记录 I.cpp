class Solution {
public:
    bool checkRecord(string s) {
        if(s.length() < 2) return true;
        if(s.length() <= 2) {
            if(s[0] == 'A' && s[1] == 'A') return false;
        }
        int cntA = 0;
        if(s[0] == 'A') cntA++;
        if(s[1] == 'A') cntA++;
        for(int i = 2; i < s.length(); i++) {
            if(s[i] == 'A') cntA++;
            if(cntA >= 2) return false;
            if(s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') return false;
        }
        return true;
    }
};