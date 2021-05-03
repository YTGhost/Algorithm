// 2021/05/03 每日一题
class Solution {
public:
    int reverse(int x) {
        int res = 0;;
        while(x)
        {
            if(res < INT_MIN / 10 || res > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

// LeetCode究极班打卡
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x)
        {
            if(ans > 0 && ans > (INT_MAX - x%10) / 10) return 0;
            if(ans < 0 && ans < (INT_MIN - x%10) / 10) return 0;
            ans = ans * 10 + x%10;
            x /= 10;
        }
        return ans;
    }
};

class Solution {
public:
    int reverse(int x) {
        int max = 0x7fffffff, min = 0x80000000;
        long sum = 0;
        for(;x;sum = sum*10 + x%10,x/=10);
        return sum>max || sum<min ? 0 : sum;
    }
};