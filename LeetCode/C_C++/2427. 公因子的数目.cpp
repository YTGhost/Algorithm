class Solution {
public:
    int commonFactors(int a, int b) {
        int n = min(a, b), res = 0;
        for(int i = 1; i <= n; i++) {
            if(a % i == 0 && b % i == 0) {
                res++;
            }
        }
        return res;
    }
};