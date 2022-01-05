class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length()), carry = 0, i;
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0; i < n; i++) {
            carry += i < a.length() ? a[i] == '1' : 0;
            carry += i < b.length() ? b[i] == '1' : 0;
            res += carry % 2 ? '1' : '0';
            carry /= 2;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};