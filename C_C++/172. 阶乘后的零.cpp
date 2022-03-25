class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i = 5; i <= n; i += 5) {
            int x = i;
            while(x % 5 == 0) {
                res++;
                x /= 5;
            }
        }
        return res;
    }
};