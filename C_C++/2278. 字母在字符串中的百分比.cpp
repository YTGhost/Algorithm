class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length(), cnt = 0;
        for(auto c : s) {
            if(c == letter) {
                cnt++;
            }
        }
        return cnt * 100 / n;
    }
};