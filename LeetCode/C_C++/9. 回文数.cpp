// 将数字转换成字符串，双指针
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str = to_string(x);
        int l = 0, r = str.length() - 1;
        for( ; l < r; l++, r--)
        {
            if(str[l] != str[r]) return false;
        }
        return true;
    }
};
// 不讲数字转换为字符串解法
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