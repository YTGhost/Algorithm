class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a * a <= c / 2; a++) {
            int b = sqrt(c - a * a);
            if (a * a + b * b == c) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        while(l <= r)
        {
            long long total = l * l + r * r;
            if(total > c) r--;
            else if(total < c) l++;
            else return true;
        }
        return false;
    }
};