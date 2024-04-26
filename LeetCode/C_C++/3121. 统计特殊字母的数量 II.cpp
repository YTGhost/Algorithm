class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<bool> result(26, true);
        vector<bool> hash1(26);
        vector<bool> hash2(26);
        for(auto c : word) {
            if(c >= 'a' && c <= 'z') {
                int t = c - 'a';
                if(hash2[t]) {
                    result[t] = false;
                }
                hash1[t] = true;
            } else if(c >= 'A' && c <= 'Z') {
                int t = c - 'A';
                hash2[t] = true;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(result[i] && hash1[i] && hash2[i]) {
                res++;
            }
        }
        return res;
    }
};