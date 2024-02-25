class Solution {
public:
    int hash1[26];
    int hash2[26];
    int rearrangeCharacters(string s, string target) {
        for(auto c : s) {
            hash1[c - 'a']++;
        }
        for(auto c : target) {
            hash2[c - 'a']++;
        }
        int res = 100;
        for(int i = 0; i < 26; i++) {
            if(hash2[i]) {
                res = min(res, hash1[i] / hash2[i]);
            }
        }
        return res;
    }
};