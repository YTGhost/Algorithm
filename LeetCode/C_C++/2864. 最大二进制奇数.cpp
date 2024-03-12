class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0, n = s.length();
        for(auto c : s) {
            if(c == '1') {
                cnt++;
            }
        }
        string res(cnt - 1, '1');
        for(int i = 0; i < n - cnt; i++) {
            res += "0";
        }
        res += "1";
        return res;
    }
};