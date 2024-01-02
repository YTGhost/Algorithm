class Solution {
public:
    bool check(char a, char b) {
        if(a >= 'A' && a <= 'Z') {
            a = 'a' + a - 'A';
        }
        if(b >= 'A' && b <= 'Z') {
            b = 'a' + b - 'A';
        }
        return a == b;
    }
    bool checkRange(char a) {
        if(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z' || a >= '0' && a <= '9') {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = s.size();
        while(l < r) {
            while(l < n && !checkRange(s[l])) l++;
            while(r >= 0 && !checkRange(s[r])) r--;
            if(l < r) {
                if(!check(s[l], s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool check(char c){
        if(c >= '0' && c <= '9' || c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z') return true;
        else return false;
    }
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int l = -1, r = s.length();
        while(l < r)
        {
            do l++; while(l < s.length() && !check(s[l]));
            do r--; while(r > -1 && !check(s[r]));
            if(l < r){
                if((s[l] >= '0' && s[l] <= '9' && s[l] != s[r]) || 
                (s[l] >= 'a' &&  s[l] <= 'z' && s[l] != s[r] && s[l]-32 != s[r]) ||
                (s[l] >= 'A' &&  s[l] <= 'Z' && s[l] != s[r] && s[l]+32 != s[r])) return false;
            }
            
        }
        return true;
    }
};