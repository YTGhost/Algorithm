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