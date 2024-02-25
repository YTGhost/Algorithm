class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        int sign = 0;
        while(l < r)
        {
            if(s[l++] != s[r--]){
                l--;
                sign++;
                if(sign >= 2){
                    l = 0, r = s.length() - 1;
                    sign = 0;
                    while(l < r)
                    {
                        if(s[l++] != s[r--]){
                            r++;
                            sign++;
                            if(sign >= 2) return false;
                        }
                    }
                    return true;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r)
        {
            if(s[l++] != s[r--]){
                return valid(s, l, r+1) || valid(s, l-1, r);
            }
        }
        return true;
    }

    bool valid(string s, int l, int r){
        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};
