class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int hash[26];
        for(int i = 0; i < 26; i++) {
            hash[order[i] - 'a'] = i; 
        }
        int n = words.size();
        for(int i = 1; i < n; i++) {
            string word1 = words[i-1];
            string word2 = words[i];
            bool flag = true;
            for(int j = 0; j < min(word1.length(), word2.length()); j++) {
                if(word1[j] != word2[j]) {
                    if(hash[word1[j] - 'a'] > hash[word2[j] - 'a']) return false;
                    flag = false;
                    break;
                }
            }
            if(flag && word1.length() > word2.length()) return false;
        }
        return true;
    }
};