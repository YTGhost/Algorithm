class Solution {
public:
    bool checkPalindrome(const string &a, int left, int right) {
        while(left < right && a[left] == a[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
    bool check(const string &a, const string &b) {
        int n = a.size();
        int l = 0, r = n - 1;
        while(l < r && a[l] == b[r]) {
            l++;
            r--;
        }
        if(l >= r) return true;
        return checkPalindrome(a, l, r) || checkPalindrome(b, l, r);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};