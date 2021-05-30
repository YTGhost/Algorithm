class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};