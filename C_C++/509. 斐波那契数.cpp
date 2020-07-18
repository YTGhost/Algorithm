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