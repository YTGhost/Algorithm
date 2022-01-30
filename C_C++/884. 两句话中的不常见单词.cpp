class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        string str = s1 + " " + s2;
        string temp = "";
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ' ') {
                m[temp]++;
                temp = "";
            } else {
                temp += str[i];
            }
        }
        m[temp]++;
        vector<string> res;
        for(auto item : m) {
            if(item.second == 1) {
                res.push_back(item.first);
            }
        }
        return res;
    }
};