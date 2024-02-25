class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string t = "12210111011122000010020202";
        for(auto word : words) {
            if(word.length() == 1) res.push_back(word);
            else {
                bool flag = true;
                for(int i = 1; i < word.length(); i++) {
                    if(t[tolower(word[i])  - 'a'] != t[tolower(word[i - 1])  - 'a']) {
                        flag = false;
                        break;
                    }
                }
                if(flag) res.push_back(word);
            }
        }
        return res;
    }
};