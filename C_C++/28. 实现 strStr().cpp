// 暴力
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.length()) return 0;
        for(int i = 0; i < haystack.length(); i++) {
            int j = i;
            for(; j < haystack.length() && j - i < needle.length(); j++) {
                if(needle[j-i] != haystack[j]) break;
            }
            if(j - i == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};