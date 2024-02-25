class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0, n = s.length();
        for(auto word : words) {
            for(auto c : word) {
                if(i >= n || c != s[i++]) return false;
            }
            if(i == n) return true;
        }
        return false;
    }
};