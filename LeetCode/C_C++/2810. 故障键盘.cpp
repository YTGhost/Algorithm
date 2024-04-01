class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto c : s) {
            if(c == 'i') {
                reverse(res.begin(), res.end());
                continue;
            }
            res += c;
        }
        return res;
    }
};