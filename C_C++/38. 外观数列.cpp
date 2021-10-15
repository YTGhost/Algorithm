class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = "11";
        n -= 2;
        while(n--) {
            string res;
            char t = str[0];
            int i = 0;
            for(int j = 1; j < str.length(); j++) {
                if(str[j] != t) {
                    res += to_string(j - i) + t;
                    t = str[j];
                    i = j;
                }
            }
            res += to_string(str.length() - i) + t;
            str = res;
        }
        return str;
    }
};