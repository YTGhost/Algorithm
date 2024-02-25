class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        int sign = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(i == 0 && str[i] == ' ')
            {
                while(str[i] == ' ') i++;
            }
            if(str[i] == '+'){
                if(sign == 0) sign = 1;
                else{
                    break;
                }
            }else if(str[i] == '-'){
                if(sign == 0) sign = -1;
                else{
                    break;
                }
            }else if(str[i] >= '0' && str[i] <= '9'){
                if(sign == 0) sign = 1;
                ans = ans*10 + (str[i] - '0');
                if(ans > INT_MAX) break;
            }else{
                break;
            }
        }
        ans = sign >= 0 ? ans : ans * -1;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return ans;
    }
};