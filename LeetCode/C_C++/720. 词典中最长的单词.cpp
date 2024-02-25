class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> hash;
        string res = "";
        for(auto word : words) {
            hash.insert(word);
        }
        for(auto word : words) {
            bool flag = true;
            for(int i = 1; i < word.length(); i++) {
                if(!hash.count(word.substr(0, i))) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                if(word.length() > res.length()) {
                    res = word;
                } else if(word.length() == res.length() && word < res) {
                    res = word;
                }
            }
        }
        return res;
    }
};