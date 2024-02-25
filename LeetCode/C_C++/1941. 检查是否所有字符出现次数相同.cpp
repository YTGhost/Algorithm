class Solution {
public:
    int hash[26];
    bool areOccurrencesEqual(string s) {
        for(auto c : s) {
            hash[c - 'a']++;
        }
        int t = hash[s[0] - 'a'];
        for(int i = 1; i < 26; i++) {
            if(hash[i] && hash[i] != t) {
                return false;
            }
        }
        return true;
    }
};