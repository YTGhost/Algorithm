class Solution {
public:
    int hash[26];
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        for(auto c : allowed) {
            hash[c - 'a'] = 1;
        }
        for(auto word : words) {
            bool flag = true;
            for(int i = 0; i < word.length(); i++) {
                if(hash[word[i] - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res++;
            }
        }
        return res;
    }
};