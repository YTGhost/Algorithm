class Solution {
public:
    int hash[26];
    bool isAnagram(string s, string t) {
        if(s == t || s.length() != t.length()) return false;
        for(auto c : s) {
            hash[c - 'a']++;
        }
        for(auto c : t) {
            if(!hash[c - 'a']) return false;
            hash[c - 'a']--;
        }
        return true;
    }
};