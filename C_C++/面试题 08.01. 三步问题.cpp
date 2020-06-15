class Solution {
public:
    int waysToStep(int n) {
        if(n == 1) return 1;
        long a = 0, b = 1, c = 1, d = 2;
        for(int i = 2; i < n; i++)
        {
            a = b;
            b = c;
            c = d;
            d = a % 1000000007 + b % 1000000007 + c % 1000000007;
        }
        return d % 1000000007;
    }
};