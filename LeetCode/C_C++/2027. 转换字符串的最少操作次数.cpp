class Solution {
public:
    int minimumMoves(string s) {
        int res = 0, i = 0;
        while(i < s.length()) {
            if(s[i] == 'X') {
                res++;
                i += 3;
            } else {
                i++;
            }
        }
        return res;
    }
};