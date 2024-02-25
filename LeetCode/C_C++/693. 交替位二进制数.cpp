class Solution {
public:
    bool hasAlternatingBits(int n) {
        int t = -1;
        while(n) {
            if(t != -1 && t == (n & 1)) return false;
            t = n & 1;
            n >>= 1;
        }
        return true;
    }
};