class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0, j = 0, n = word1.length(), m = word2.length();
        while(i < n && j < m) {
            res += word1[i++];
            res += word2[j++];
        }
        while(i < n) {
            res += word1[i++];
        }
        while(j < m) {
            res += word2[j++];
        }
        return res;
    }
};