class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto word : words) {
            bool flag = true;
            if(word.length() < pref.length()) continue;
            for(int i = 0; i < pref.length(); i++) {
                if(pref[i] != word[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res++;
        }
        return res;
    }
};