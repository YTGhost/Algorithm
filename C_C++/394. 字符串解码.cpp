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