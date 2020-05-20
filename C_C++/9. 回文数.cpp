class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long sum = 0;
        while(x)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return sum == temp ? true : false;
    }
};