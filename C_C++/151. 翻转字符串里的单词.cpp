class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        vector<string> a;
        string t = "";
        for(int i = 0, sign = 0, start = 0, end = 0; i < s.length(); i++)
        {
            if(s[i] == ' '){
                sign = 0;
                continue;
            }
            if(sign == 0){
                start = i;
                sign = 1;
                if((i+1 < s.length() && s[i+1] == ' ') || i+1 == s.length()) a.push_back(s.substr(start, 1));
            }else{
                end = i;
                if((i+1 < s.length() && s[i+1] == ' ') || i+1 == s.length())
                {
                    reverse(s.begin()+start, s.begin()+end+1);
                    a.push_back(s.substr(start, end+1-start));
                }
            }
        }
        for(int i = 0; i < a.size(); i++)
        {
            if(i != a.size()-1) t += a[i] + " ";
            else t += a[i];
        }
        return t;
    }
};