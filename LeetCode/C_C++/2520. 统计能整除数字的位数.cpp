class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        string t = to_string(num);
        for(auto c : t) {
            if(num % (c - '0') == 0) {
                res++;
            }
        }
        return res;
    }
};