class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<bool> mask(n);
        for(int i = 0; i < n; i++) {
            for(auto word : words) {
                bool flag = false;
                for(int k = 0; k < word.size(); k++) {
                    if(k + i >= s.size() || s[k + i] != word[k]) {
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                for(int j = i; j < i + word.size(); j++) {
                    mask[j] = true;
                }
            }
        }
        string res = "";
        for(int i = 0; i < n; i++) {
            if(mask[i] && (i == 0 || !mask[i - 1])) {
                res += "<b>";
            }
            res += s[i];
            if(mask[i] && (i == n - 1 || !mask[i + 1])) {
                res += "</b>";
            }
        }
        return res;
    }
};