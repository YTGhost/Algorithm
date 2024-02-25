// 2021/04/10每日一题
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n % 5 == 0) n /= 5;
        while(n % 3 == 0) n /= 3;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n % 5 == 0) n /= 5;
        while(n % 3 == 0) n /= 3;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};