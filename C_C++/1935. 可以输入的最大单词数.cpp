class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> hash(26, true);
        int res = 0;
        for(auto c : brokenLetters) {
            hash[c - 'a'] = false;
        }
        for(int i = 0; i < text.length(); i++) {
            bool flag = true;
            while(i < text.length() && text[i] != ' ') {
                if(!hash[text[i] - 'a']) {
                    flag = false;
                }
                i++;
            }
            if(flag) res++;
        }
        return res;
    }
};