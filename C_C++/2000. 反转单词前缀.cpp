class Solution {
public:
    string reverseStr(string& word, int idx) {
        int l = 0, r = idx;
        while(l < r) {
            swap(word[l++], word[r--]);
        }
        return word;
    }
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == ch) {
                idx = i;
                break;
            }
        }
        return idx == -1 ? word : reverseStr(word, idx);
    }
};