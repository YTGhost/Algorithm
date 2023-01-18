class Solution {
public:
    int countAsterisks(string s) {
        bool left = false;
        int res = 0;
        for(auto c : s) {
            if(c == '*' && !left) res++;
            if(c == '|' && !left) left = true;
            else if(c == '|' && left) left = false;
        }
        return res;
    }
};