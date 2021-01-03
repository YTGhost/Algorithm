class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int a = 1, b = 1;
        for(int i = 2; i < n; i++) {
            a += b;
            b = a - b;
        }
        return a;
    }
};

class Solution {
public:
    int fib(int N) {
        if(N == 0 || N == 1) return N;
        int a = 0, b = 1, c = 0, i = 1;
        while(i < N)
        {
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return c;
    }
};