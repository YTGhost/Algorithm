class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1 = 0, cnt2 = 0;
        int hash1[26], hash2[26];
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));
        unordered_map<int, int> m;
        for(auto c : word1) {
            hash1[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(hash1[i]) {
                m[hash1[i]]++;
            }
        }
        for(auto c : word2) {
            hash2[c - 'a']++;
            if(!hash1[c - 'a']) {
                return false;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(hash2[i]) {
                m[hash2[i]]--;
                if(m[hash2[i]] == 0) {
                    m.erase(hash2[i]);
                }
            }
        }
        return m.empty();
    }
};