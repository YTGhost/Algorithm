class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8 * (long)n)) / 2;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        int idx = 1;
        while(n - idx >= 0) {
            n -= idx++;
            res++;
        }
        return res;
    }
};