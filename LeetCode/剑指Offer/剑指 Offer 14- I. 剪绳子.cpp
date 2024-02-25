class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        int sum = 1;
        while(n > 4)
        {
            sum *= 3;
            n -= 3;
        }
        return sum*n;
    }
};

class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        if(n%3 == 0) return pow(3, n/3);
        else if(n%3 == 1) return pow(3, n/3-1) * 4;
        else return pow(3, n/3) * 2;
    }
};