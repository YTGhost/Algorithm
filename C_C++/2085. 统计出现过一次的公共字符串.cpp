class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int res = 0;
        for(auto word : words1) {
            m1[word]++;
        }
        for(auto word : words2) {
            m2[word]++;
        }
        for(auto &[k, v] : m1) {
            if(v == 1 && m2[k] == 1) {
                res++;
            }
        }
        return res;
    }
};