class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s;
        unordered_map<char, char> s2t;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++) {
            if(!s2t.count(s[i]) && !t2s.count(t[i])) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if(s2t.count(s[i]) && t2s.count(t[i])){
                if(s2t[s[i]] !=  t[i] || t2s[t[i]] != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};