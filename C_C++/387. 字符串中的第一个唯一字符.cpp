class Solution {
public:
    int hash[26];
    int index[26];
    int firstUniqChar(string s) {
        for(int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a']++;
            index[s[i] - 'a'] = i;  
        }
        for(auto c : s) {
            if(hash[c - 'a'] == 1) {
                return index[c - 'a'];
            }
        }
        return -1;
    }
};