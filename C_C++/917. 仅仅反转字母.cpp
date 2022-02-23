class Solution {
public:
    bool check(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            if(check(s[l]) && check(s[r])) {
                swap(s[l++], s[r--]);
            } else if(!check(s[l])) {
                l++;
            } else {
                r--;
            }
        }
        return s;
    }
};