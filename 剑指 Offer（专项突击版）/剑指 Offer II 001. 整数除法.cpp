class Solution {
public:
    int divide(int a, int b) {
        bool isNegative = false;
        if(a == INT_MIN && b == -1) return INT_MAX;
        if(a == INT_MIN && b == 1) return INT_MIN;
        if(a <= 0 && b > 0) {
            b = -b;
            isNegative = true;
        }
        if(a > 0 && b <= 0) {
            a = -a;
            isNegative = true;
        }
        if(a > 0 && b > 0) {
            a = -a, b = -b;
        }
        int res = 0, t = b;
        while(a <= b) {
            int cnt = 1, t = b;
            while(t > INT_MIN >> 1 && a <= t + t) {
                cnt += cnt;
                t += t;
            }
            res += cnt;
            a -= t;
        }
        return isNegative ? -res : res;
    }
};