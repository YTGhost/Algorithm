class Solution {
public:
    bool isNumber(string& token) {
        return token != "+" && token != "-" && token != "*" && token != "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            string& token = tokens[i];
            if(isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num2 - num1);
                        break;
                    case '/':
                        stk.push(num2 / num1);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                }
            }
        }
        return stk.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(atoi(tokens[i].c_str()));
            }else{
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();
                if(tokens[i] == "+")    s.push(t2+t1);
                else if(tokens[i] == "-")   s.push(t2-t1);
                else if(tokens[i] == "*")   s.push(t2*t1);
                else if(tokens[i] == "/")   s.push(t2/t1);
            }
        }
        return s.top();
    }
};