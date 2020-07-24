class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        long sum = 1;
        while(n > 4)
        {
            sum = 3 * sum;
            sum %= 1000000007;
            n -= 3;
        }
        return sum*n%1000000007;
    }
};