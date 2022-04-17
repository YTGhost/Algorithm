class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> set;
        unordered_map<string, int> map;
        int maxCnt = 0;
        for(auto word : banned) {
            set.insert(word);
        }
        string word;
        string maxWord;
        int n = paragraph.size();
        for(int i = 0; i <= n; i++) {
            if(i < n && isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } else if(word.size() > 0) {
                if(!set.count(word)) {
                    map[word]++;
                    if(map[word] > maxCnt) {
                        maxCnt = map[word];
                        maxWord = word;
                    }
                }
                word = "";
            }
        }
        return maxWord;
    }
};