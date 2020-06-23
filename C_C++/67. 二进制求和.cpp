class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0;
        int carry = 0;
        int numA = atoi(a.c_str());
        string ans;
        while(i < a.length() && i < b.length())
        {
            int t = a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0' + carry;
            carry = 0;
            ans = to_string(t%2) + ans;
            if(t >= 2) carry = t/2;
            i++;
        }
        while(i < a.length())
        {
            int t = a[a.length()-1-i] - '0' + carry;
            carry = 0;
            ans = to_string(t%2) + ans;
            if(t >= 2) carry = t/2;
            i++;
        }
        while(i < b.length())
        {
            int t = b[b.length()-1-i] - '0' + carry;
            carry = 0;
            ans = to_string(t%2) + ans;
            if(t >= 2) carry = t/2;
            i++;
        }
        if(carry != 0) ans = to_string(carry) + ans;
        return ans;
    }
};