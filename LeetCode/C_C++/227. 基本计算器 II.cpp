class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char pre = '+';
        int n = s.length();
        int num = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(isdigit(s[i])) num = num * 10 + (s[i] - '0');
            if(!isdigit(s[i]) && s[i] != ' ' || i == n-1) {
                switch (pre) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                pre = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};