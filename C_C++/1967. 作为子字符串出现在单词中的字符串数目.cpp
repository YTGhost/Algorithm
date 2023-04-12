class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for(auto str : patterns) {
            if(word.find(str) != -1) {
                res++;
            }
        }
        return res;
    }
};