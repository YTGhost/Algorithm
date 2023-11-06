class Solution {
public:
    bool check(string& word) {
        int n = word.size();
        if((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') &&
        (word[n - 1] == 'a' || word[n - 1] == 'e' || word[n - 1] == 'i' || word[n - 1] == 'o' || word[n - 1] == 'u')) {
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++) {
            if(check(words[i])) {
                res++;
            }
        }
        return res;
    }
};