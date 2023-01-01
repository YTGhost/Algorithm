class Solution {
public:
    int hash[26];
    char repeatedCharacter(string s) {
        char res;
        for(auto c : s) {
            if(hash[c - 'a']) {
                res = c;
                break;
            } else {
                hash[c - 'a']++;
            }
        }
        return res;
    }
};