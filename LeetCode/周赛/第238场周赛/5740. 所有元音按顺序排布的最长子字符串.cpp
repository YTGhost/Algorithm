class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int a[] = {'a', 'e', 'i', 'o', 'u'};
        int res = 0;
        int len = 0;
        int sign = 0;
        for(int i = 0; i < word.length(); i++)
        {
            if(sign == 0) {
                if(word[i] == 'a') {
                    len++;
                    sign = 1;
                }
            } else if(sign == 1) {
                if(word[i] == 'a') {
                    len++;
                } else if(word[i] == 'e') {
                    len++;
                    sign = 2;
                } else {
                    len = 0;
                    sign = 0;
                }
            } else if(sign == 2) {
                if(word[i] == 'e') {
                    len++;
                } else if(word[i] == 'i') {
                    len++;
                    sign = 3;
                } else {
                    len = 0;
                    sign = 0;
                    i--;
                }
            } else if(sign == 3) {
                if(word[i] == 'i') {
                    len++;
                } else if(word[i] == 'o') {
                    len++;
                    sign = 4;
                } else {
                    len = 0;
                    sign = 0;
                    i--;
                }
            } else if(sign == 4) {
                if(word[i] == 'o') {
                    len++;
                } else if(word[i] == 'u') {
                    len++;
                    sign = 5;
                } else {
                    len = 0;
                    sign = 0;
                    i--;
                }
            } else if(sign == 5) {
                if(word[i] == 'u') {
                    len++;
                } else {
                    res = max(res, len);
                    len = 0;
                    sign = 0;
                    i--;
                }
            }
        }
        if(len && sign == 5) res = max(res, len);
        return res;
    }
};