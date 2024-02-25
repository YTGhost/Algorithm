class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size()-1, m = num2.size()-1;
        string res;
        int carry = 0;
        while(n >= 0 || m >= 0 || carry)
        {
            if(n >= 0) carry += num1[n--] - '0';
            if(m >= 0) carry += num2[m--] - '0';
            res += to_string(carry%10);
            carry /= 10; 
        }
        reverse(res.begin(), res.end());
        return res;
    }
};