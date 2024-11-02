class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};

class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k) {
            return 0;
        }
        int res = 0;
        while (n && k) {
            int a = n & 1;
            int b = k & 1;
            if (a == 0 && b == 1) {
                return -1;
            }
            if (a == 1 && b == 0) {
                res++;
            }
            n >>= 1;
            k >>= 1;
        }
        if (k != 0) {
            return -1;
        }
        while (n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};