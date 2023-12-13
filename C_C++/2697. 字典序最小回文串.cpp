class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                char t = s[l] < s[r] ? s[l] : s[r];
                s[l] = t;
                s[r] = t;
            }
            l++;
            r--;
        }
        return s;
    }
};