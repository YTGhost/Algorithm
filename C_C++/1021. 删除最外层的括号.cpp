class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') stk.pop();
            if(!stk.empty()) res += s[i];
            if(s[i] == '(') stk.push('(');
        }
        return res;
    }
};