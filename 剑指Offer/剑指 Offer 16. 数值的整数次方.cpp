// 快速幂
class Solution {
public:
    double myPow(double x, int n) {
        bool sign = n < 0;
        long b = n;
        if(sign) b = -b;
        double res = 1;
        while(b)
        {
            if(b&1) res *= x;
            b >>= 1;
            x *= x;
        }
        return sign ? 1/res : res;
    }
};