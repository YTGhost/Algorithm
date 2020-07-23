class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        int a = 0, b = 1;
        for(int i = 1; i < n; i++)
        {
            b = a + b;
            a = b - a;
            b %=1000000007;
        }
        return b;
    }
};