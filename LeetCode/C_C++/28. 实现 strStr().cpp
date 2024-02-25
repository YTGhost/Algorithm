class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};

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