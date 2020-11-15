class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k) return "0";
        while(k--)
        {
            for(int i = 1; i < num.length(); i++)
            {
                if(num[i] < num[i-1]) {
                    num.erase(i-1, 1);
                    while(num.length() > 1 && num[0] == '0') num.erase(0, 1);
                    break;
                }
                if(i == num.length()-1) num.erase(i, 1);
            }
        }
        return num;
    }
};