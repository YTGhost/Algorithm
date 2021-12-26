class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> words;
        string temp = "";
        for(int i = 0; i < text.length(); i++) {
            if(text[i] == ' ') {
                words.push_back(temp);
                temp = "";
            }
            else {
                temp += text[i];
            }
        }
        if(temp != "") words.push_back(temp);
        for(int i = 0; i < words.size() - 2; i++) {
            if(words[i] == first && words[i+1] == second) {
                res.push_back(words[i+2]);
            }
        }
        return res;
    }
};