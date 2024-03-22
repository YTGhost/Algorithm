class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(!stk.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                if (s[i] == ')' && stk.top() != '(') {
                    return false;
                } else if(s[i] == ']' && stk.top() != '[') {
                    return false;
                } else if(s[i] == '}' && stk.top() != '{') {
                    return false;
                } 
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '[') {
                sk.push(c);
            } else if(!sk.empty()) {
                if(c == ')' && sk.top() != '(' || c == '}' && sk.top() != '{' || c == ']' && sk.top() != '[') {
                    return false;
                } else {
                    sk.pop();
                }
            } else {
                return false;
            }
        }
        return sk.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push(s[i]);
            }else{
                if(stack.size() == 0)   return false;
                if(s[i] == ')' && stack.top() == '(')   stack.pop();
                else if(s[i] == ']' && stack.top() == '[')  stack.pop();
                else if(s[i] == '}' && stack.top() == '{')  stack.pop();
                else    return false;
            }
        }
        return stack.empty();
    }
};