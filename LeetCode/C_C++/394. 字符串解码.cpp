class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> stk;
        int ptr = 0;
        function<string()> getDigits = [&](){
            string str = "";
            while(s[ptr] >= '0' && s[ptr] <= '9') {
                str.push_back(s[ptr++]);
            }
            return str;
        };
        function<string(const vector<string>&)> getString = [&](const vector<string> &t) {
            string str = "";
            for(const auto &s : t) {
                str += s;
            }
            return str;
        };
        while(ptr < n) {
            char cur = s[ptr];
            if (cur >= '0' && cur <= '9') {
                string num = getDigits();
                stk.push(num);
            } else if(cur == '[' || cur >= 'a' && cur <= 'z') {
                stk.push(string(1, s[ptr++]));
            } else {
                ptr++;
                vector<string> t;
                while(stk.top() != "[") {
                    t.push_back(stk.top());
                    stk.pop();
                }
                reverse(t.begin(), t.end());
                stk.pop();
                int num = stoi(stk.top());
                stk.pop();
                string str = getString(t);
                string temp = "";
                while(num--) temp += str;
                stk.push(temp);
            }
        }
        string res = "";
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};

class Solution {
public:
    string decodeString(string s) {
        stack<string> strs;
        stack<int> nums;
        int sum = 0;
        string t = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9'){
                sum = sum*10 + s[i] - '0';
            }else if(s[i] == '['){
                strs.push(t);
                nums.push(sum);
                t = "";
                sum = 0;
            }else if(s[i] == ']'){
                int k = nums.top();
                nums.pop();
                for(int j = 0; j < k; j++) strs.top() += t;
                t = strs.top();
                strs.pop();
            }else{
                t += s[i];
            }
        }
        return t;
    }
};