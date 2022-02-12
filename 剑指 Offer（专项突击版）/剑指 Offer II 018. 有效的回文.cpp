class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto c : s) {
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
                if(c >= 'A' && c <= 'Z') {
                    str += 'a' + c - 'A';
                } else {
                    str += c;
                }
            }
        }
        int l = 0, r = str.length() - 1;
        while(l < r) {
            if(str[l++] != str[r--]) return false;
        }
        return true;
    }
};