class Solution {
public:
    double quickPow(double x, long long n){
        if(n == 0) return 1.0;
        double y = quickPow(x, n/2);
        return n % 2 ? y * y * x : y * y; 
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickPow(x, N) : 1.0 / quickPow(x, -N);
    }
};