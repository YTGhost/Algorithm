class Solution {
public:
    int hash[26];
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        for(auto c : s) hash[c - 'a']++;
        for(auto c : t)
        {
            if(--hash[c - 'a'] < 0) return false;
        }
        return true;
    }
};