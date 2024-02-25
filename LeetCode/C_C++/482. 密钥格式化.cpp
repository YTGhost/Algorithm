class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;
        for(auto c : s) {
            if(c == '-') continue;
            if(c >= 'a' && c <= 'z') {
                c = 'A' + c - 'a';
            }
            str += c;
        }
        int n = str.size();
        int cnt = n % k;
        string res;
        if(cnt > 0) {
            for(int i = 0; i < cnt; i++) {
                res += str[i];
            }
            res += "-";
        }
        for(int i = cnt; i < n; i++) {
            res += str[i];
            int t = i - cnt + 1;
            if(t % k == 0) {
                res += "-";
            }
        }
        return res.substr(0, res.size() - 1);
    }
};