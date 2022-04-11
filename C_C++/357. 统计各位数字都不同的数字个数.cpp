class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int res = 10;
        for(int i = 2, last = 9; i <= n; i++) {
            int cur = last * (10 - i + 1);
            res += cur;
            last = cur;
        }
        return res;
    }
};