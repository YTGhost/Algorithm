class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<bool> hash1(26);
        vector<bool> hash2(26);
        for(int i = 0; i < n; i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                hash1[word[i] - 'a'] = true;
            } else if(word[i] >= 'A' && word[i] <= 'Z') {
                hash2[word[i] - 'A'] = true;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(hash1[i] && hash2[i]) {
                res++;
            }
        }
        return res;
    }
};