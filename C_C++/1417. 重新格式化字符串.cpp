class Solution {
public:
    string reformat(string s) {
        string a, b;
        for(auto c : s) {
            if(c >= '0' && c <= '9') {
                a += c;
            } else {
                b += c;
            }
        }
        string res;
        int n = a.length(), m = b.length();
        if(abs(n - m) <= 1) {
            int i = 0, j = 0;
            while(i < n && j < m) {
                if (n > m) {
                    res += a[i++];
                    res += b[j++];
                } else {
                    res += b[j++];
                    res += a[i++];
                }
            }
            while(i < n) {
                res += a[i++];
            }
            while(j < m) {
                res += b[j++];
            }
        }
        return res;
    }
};